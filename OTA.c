/*****************************************************************************
 * | @file    : battery_update_app_version.h
 * | @author  : liubo
 * | @version : V1.0.1
 * | @date    : 2024-08-08
 * --------------
 * | @brief   : V1.0.0 update battery basic version
 * |            V1.0.1 running in  scheduler
 ******************************************************************************/
#include "battery_update_app_version.h"

#include <stdint.h>
#include <string.h>

#include "battery_app_bin.h"
#include "battery_communicate.h"
#include "battery_send_communicate.h"
#include "debug.h"
#include "hc32_ll_utility.h"
#include "stdbool.h"

// #define SOFTVERSION_ADDRESS (400 + 18)
#define SOFTVERSION_ADDRESS 1042
static uint8_t          battery_version_new[3];
static uint8_t          battery_version_old[3];
battery_update_status_t battery_update_status = {
    .need_update         = false,
    .battery_updating    = false,
    .battery_update_step = UPDATE_OVER,
};
void battery_update_app_version(void)
{
    static uint32_t cnt0 = 0;
    cnt0++;
    if (cnt0 % 10 == 0 &&
        battery_update_status.battery_updating == false) {  // 延时 10 * 40ms
        cnt0 = 0;
        request_battery_static_data();
        if (get_battery_app_version(battery_version_new, 3) == false) {
            Debug("%s %d get battery app version waiting!\r\n", __func__,
                  __LINE__);
        }
        else {  // get version sucess
            for (uint8_t i = 0; i < 3; i++) {
                battery_version_new[i] =
                    battery_app_bin[SOFTVERSION_ADDRESS + i];
                Debug("%s %d battery_version_old %d!\r\n", __func__, __LINE__,
                      battery_version_old[i]);
                Debug("%s %d battery_version_new %d!\r\n", __func__, __LINE__,
                      battery_version_new[i]);
                if (battery_version_old[i] != battery_version_new[i]) {
                    battery_update_status.need_update         = true;
                    battery_update_status.battery_update_step = UPDATE_BEGAIN;
                    break;
                }
                else {
                    battery_update_status.need_update = false;
                }
            }
        }
    }

    if (battery_update_status.need_update == true) {
        // 开始升级
        battery_update_begain();
    }
}

void battery_update_begain(void)
{
    // static uint8_t enter_feedback_result = FAIL;
    // static uint8_t ready_update_result = FAIL;
    static uint8_t  result         = FAIL;
    static uint16_t package_number = 0;
    static uint8_t  firmware_segment[UPDATE_PACKAGE_SIZE];
    static int      package_index = 0;

    switch (battery_update_status.battery_update_step) {
        case UPDATE_BEGAIN:
            battery_update_status.battery_updating    = true;
            battery_update_status.battery_update_step = ENTER_BOOTLOADER;
            break;
        case ENTER_BOOTLOADER:
            notify_battery_into_boot();
            battery_update_status.battery_update_step = WAIT_ENTER_BOOTLOADER;
            break;
        case WAIT_ENTER_BOOTLOADER:  // wait enter feedback
            result = wait_battery_update_feedback();

            if (result == SUCCESS) {
                battery_update_status.battery_update_step =
                    ASK_BATTERY_READY_UPDATE;
            }
            else if (result == FAIL) {
                Debug("%s %d battery into boot failed!\r\n", __func__,
                      __LINE__);
                battery_update_status.need_update         = false;
                battery_update_status.battery_updating    = false;
                battery_update_status.battery_update_step = UPDATE_OVER;
                return;
            }
            else if (result == WAITING) {
                // waiting
            }
            else {
                Debug("%s %d battery update feedback error!\r\n", __func__,
                      __LINE__);
                battery_update_status.need_update         = false;
                battery_update_status.battery_updating    = false;
                battery_update_status.battery_update_step = UPDATE_OVER;
                return;
            }
            break;
        case ASK_BATTERY_READY_UPDATE:  // ask battery ready update

            package_number = sizeof(battery_app_bin) / UPDATE_PACKAGE_SIZE;

            // 不能整除增加对最后一包处理
            if (sizeof(battery_app_bin) % UPDATE_PACKAGE_SIZE != 0) {
                package_number++;
            }
            ask_battery_accept_firmware(package_number, UPDATE_PACKAGE_SIZE);
            battery_update_status.battery_update_step =
                WAIT_ASK_BATTERY_READY_UPDATE;
            break;
        case WAIT_ASK_BATTERY_READY_UPDATE:  // wait battery ready update
                                             // feedback
            result = wait_battery_update_feedback();
            if (result == SUCCESS) {
                battery_update_status.battery_update_step =
                    SEND_UP_DATE_PACKAGE;
            }
            else if (result == FAIL) {
                Debug("%s %d ask_battery_accept_firmware failed!\r\n", __func__,
                      __LINE__);
                battery_update_status.need_update         = false;
                battery_update_status.battery_updating    = false;
                battery_update_status.battery_update_step = UPDATE_OVER;
                return;
            }
            else if (result == WAITING) {
                // waiting
            }
            else {
                Debug("%s %d ask_battery_accept_firmware feedback error!\r\n",
                      __func__, __LINE__);
                battery_update_status.need_update         = false;
                battery_update_status.battery_updating    = false;
                battery_update_status.battery_update_step = UPDATE_OVER;
                return;
            }
            break;
        case SEND_UP_DATE_PACKAGE:  // send up date packge
            if (package_index < package_number) {
                memcpy(firmware_segment,
                       &battery_app_bin[package_index * UPDATE_PACKAGE_SIZE],
                       UPDATE_PACKAGE_SIZE);
                send_battery_firmware(package_index, firmware_segment);
                package_index++;
                battery_update_status.battery_update_step =
                    WAIT_SEND_UP_DATE_PACKAGE;
            }

            // 最后一帧发送后电池会重启，不会回复
            // 最后一帧发送完，判断版本号,确认升级成功
            if (package_index >= package_number) {
                battery_update_status.battery_update_step =
                    SEND_UP_DATE_PACKAGE;  // 在这一步骤等待确认升级结果

                static uint32_t cnt0       = 0;
                static uint8_t  count      = 0;
                static bool     reset_data = false;

                if (reset_data == false) {
                    reset_data = true;
                    reset_static_data_RetCode();
                }
                cnt0++;
                if (cnt0 % 2 == 0) {  // 延时 2 * 40ms 结束升级
                    cnt0 = 0;

                    // 判断版本号
                    request_battery_static_data();
                    if (get_battery_app_version(battery_version_old, 3) ==
                        false) {
                        count++;
                        Debug("%s %d get battery app version waiting %d "
                              "times!\r\n",
                              __func__, __LINE__, count);
                    }
                    else {  // get version sucess
                        reset_data = false;
                        for (uint8_t i = 0; i < 3; i++) {
                            battery_version_new[i] =
                                battery_app_bin[SOFTVERSION_ADDRESS + i];
                            Debug("%s %d battery_version_old %d!\r\n", __func__,
                                  __LINE__, battery_version_old[i]);
                            Debug("%s %d battery_version_new %d!\r\n", __func__,
                                  __LINE__, battery_version_new[i]);
                            if (battery_version_old[i] !=
                                battery_version_new[i]) {
                                battery_update_status.need_update      = false;
                                battery_update_status.battery_updating = false;
                                battery_update_status.battery_update_step =
                                    UPDATE_OVER;
                                Debug("%s %d battery_update fail!\r\n",
                                      __func__, __LINE__);
                                break;
                            }
                            else {
                                battery_update_status.need_update      = false;
                                battery_update_status.battery_updating = false;
                                battery_update_status.battery_update_step =
                                    UPDATE_OVER;
                                Debug("%s %d battery_update success!\r\n",
                                      __func__, __LINE__);
                            }
                        }
                    }

                    if (count >= 5) {
                        count                                     = 0;
                        battery_update_status.need_update         = false;
                        battery_update_status.battery_updating    = false;
                        battery_update_status.battery_update_step = UPDATE_OVER;
                        Debug("%s %d battery_update fail!\r\n", __func__,
                              __LINE__);
                    }
                }
            }

            break;
        case WAIT_SEND_UP_DATE_PACKAGE:  // send up date packge feedback

            result = wait_battery_update_feedback();
            if (result == SUCCESS) {
                battery_update_status.battery_update_step =
                    SEND_UP_DATE_PACKAGE;
            }
            else if (result == FAIL) {
                Debug("%s %d send_battery_firmware failed!\r\n", __func__,
                      __LINE__);
                battery_update_status.need_update         = false;
                battery_update_status.battery_updating    = false;
                battery_update_status.battery_update_step = UPDATE_OVER;
                return;
            }
            else if (result == WAITING) {
                // waiting
            }
            else {
                Debug("%s %d send_battery_firmware feedback error!\r\n",
                      __func__, __LINE__);
                battery_update_status.need_update         = false;
                battery_update_status.battery_updating    = false;
                battery_update_status.battery_update_step = UPDATE_OVER;
                return;
            }
            break;
        default:
            battery_update_status.need_update         = false;
            battery_update_status.battery_updating    = false;
            battery_update_status.battery_update_step = UPDATE_OVER;
            break;
    }
}

/*****************************************************************************
 * | @fn     : wait_battery_update_feedback
 * | @param  : - void
 * | @return : - uint8_t rsult
 *                       success 0
 *                       fail 1
 *                       waiting 2
 * --------------
 * | @brief  : 等待反馈 5 次，5次之后还未成功返回FAIL
 ******************************************************************************/
uint8_t wait_battery_update_feedback(void)
{
    static uint8_t  count = 0;
    static uint32_t cnt0  = 0;
    if (cnt0 % 1 == 0) {  // 延时 1 * 40ms
        cnt0 = 0;
        if (get_battery_update_feedback() ==
            false) {  // wait get version success
            count++;
            Debug("%s %d wait battery update feedback %d times!\r\n", __func__,
                  __LINE__, count);
            return WAITING;
        }
        else {  // 得到正确反馈，步骤成功
            count = 0;
            return SUCCESS;
        }
    }
    cnt0++;

    if (count >= 5) {  // 仍未成功
        count = 0;
        return FAIL;
    }
    return WAITING;
}

bool battery_is_updating(void)
{
    return battery_update_status.battery_updating;
}

void setBatUpdataState(bool state)
{
    Debug("%s %d setBatUpdataState  state:%d!\r\n", __func__, __LINE__, state);
    battery_update_status.battery_updating = state;
}

/***********************************************************
 * end of file
 **********************************************************/
