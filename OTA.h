/*****************************************************************************
 * | @file    : battery_update_app_version.h
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-08-10
 * --------------
 * | @brief   : update battery
 ******************************************************************************/
#ifndef _BATTERY_UPDATE_APP_VERSION_H_
#define _BATTERY_UPDATE_APP_VERSION_H_

#include <stdbool.h>
#include <stdint.h>

#pragma pack(1)

typedef enum {
    UPDATE_BEGAIN                 = 0u,
    ENTER_BOOTLOADER              = 1u,
    WAIT_ENTER_BOOTLOADER         = 2u,
    ASK_BATTERY_READY_UPDATE      = 3u,
    WAIT_ASK_BATTERY_READY_UPDATE = 4u,
    SEND_UP_DATE_PACKAGE          = 5u,
    WAIT_SEND_UP_DATE_PACKAGE     = 6u,

    UPDATE_OVER = 7u,
} battery_update_step_t;

typedef struct
{
    uint8_t               need_update : 1;
    uint8_t               battery_updating : 1;
    uint8_t               reserve : 6;
    battery_update_step_t battery_update_step;

} battery_update_status_t;
extern battery_update_status_t battery_update_status;

typedef enum {
    SUCCESS = 0,
    FAIL    = 1,
    WAITING = 3,
} battery_update_result;

#pragma pack()

void    battery_update_app_version(void);
void    battery_update_begain(void);
uint8_t wait_battery_update_feedback(void);
bool    battery_is_updating(void);
void    setBatUpdataState(bool state);

#endif  // #ifndef _BATTERY_UPDATE_APP_VERSION_H_

/***********************************************************
 * end of file
 **********************************************************/
