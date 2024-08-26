/*****************************************************************************
 * | @file    : battery_awake_activate.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-08-22
 * --------------
 * | @brief   : battery awakev and activate
 ******************************************************************************/
#include "battery_awake_activate.h"

#include "battery_protocol.h"
#include "debug.h"
#include "charge_driver.h"
#include "sc8815.h"
#include "drv_uart.h"
#include "charge_manager.h"
#include "drv_gpio.h"
#include "battery_recieve_analysis.h"

bool enable_battery_awake = false;
bool enable_battery_activate = false;
void battery_awake_activate(void)
{
    // 有与电池的通信且没有电池内部通信故障，电池已启动，不用处理
    if (cycle_communicate.communicate_success && AlarmData._cb.CommunicationInvalid == false) {
        return;
    }
    cycle_communicate.cycle_communicate_enable = true;  // 打开与电池的通信

    static uint32_t cnt1 = 0;
    static uint32_t cnt2 = 1;
    static uint8_t time1 = 0;
    static uint8_t time2 = 0;
    static uint8_t wait_battery_communicate_num = 0;
    // 在进行激活或唤醒的时候先等待120ms与电池建立通讯

    if (wait_battery_communicate_num < 6) {  // 20*6=120ms
        wait_battery_communicate_num++;
        Debug("statr wait battery communicate!\r\n");
        return;
    }
    wait_battery_communicate_num = 0;
    Debug("tray awake and activate battery!\r\n", time1);

    // 使用USB唤醒电池
    if (time1 < 1 && get_usb_status() == true) {  // 事件方式
        if (cnt1 % 1 == 0) {  // 大概 20X100 ms 运行一次 替代延时 todo 时序调整，支持一次上电执行后复位
            time1++;
            Debug("USB awake battery %d times!\r\n", time1);
            enable_battery_awake = true;
        }
        if (enable_battery_awake == true) {
            battery_awake();
        } else {
            cnt1++;
        }
    }

    // 三次唤醒已被执行，电池仍然没有通信，这里才会被执行
    // 使用USB激活电池
    if (time1 >= 1 && time2 < 1 && get_usb_status() == true) {
        if (cnt2 % 5 == 0) {  // 大概 20X100 ms 运行一次 替代延时
            time2++;
            Debug("USB activate battery %d times!\r\n", time2);
            enable_battery_activate = true;
        }
        if (enable_battery_activate == true) {
            battery_activate();
        } else {
            cnt2++;
        }
    }
}

bool battery_awake(void)
{
    static uint32_t cnt = 0;
    // static bool RX_set = false;

    uart_rx_gpio_reuse_init();
    // GPIO_ResetPins(UART2_USART_RX_PORT, UART2_USART_RX_PIN);

    Driver_Delay_ms(120);  // todo 修改延时方式

    GPIO_SetPins(UART2_USART_RX_PORT, UART2_USART_RX_PIN);
    uart_rx_gpio_reuse_deinit();

    enable_battery_awake = false;
    Debug("battery awake!\r\n");
}

bool battery_activate(void)
{
    SC8815_cur_config_t SC8815_cur_activate_config = {0.3, 1.38, 0.5, 5.0};
    SC8815_init(&SC8815_cur_activate_config);

    gpio_output(CHG_EN, ON);                     // 激活充电模块(SC8815电路部分)
    SC8815_update_ADC_value(&SC8815_ADC_value);  // 更新SC8815 ADC信息

    if (SC8815_ADC_value.vbat < STATIC_SOC_VOC_95) {
        SC8815_PSTOP_set(true);
    }
    Driver_Delay_ms(1);

    uart_rx_gpio_reuse_init();
    // GPIO_ResetPins(UART2_USART_RX_PORT, UART2_USART_RX_PIN);
    Driver_Delay_ms(1);

    GPIO_SetPins(UART2_USART_RX_PORT, UART2_USART_RX_PIN);
    Driver_Delay_ms(1);
    uart_rx_gpio_reuse_deinit();

    SC8815_PSTOP_set(false);
    gpio_output(CHG_EN, OFF);

    enable_battery_activate = false;
    Debug("battery activate !\r\n");
}

/***********************************************************
 * end of file
 **********************************************************/
