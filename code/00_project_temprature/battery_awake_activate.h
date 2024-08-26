/*****************************************************************************
 * | @file    : battery_awake_activate.h
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-08-22
 * --------------
 * | @brief   : battery awakev and activate
 ******************************************************************************/
#ifndef _BATTERY_AWAKE_ACTIVATE_H_
#define _BATTERY_AWAKE_ACTIVATE_H_

#include "stdbool.h"

#pragma pack(1)
#pragma pack()

void battery_awake_activate(void);
bool battery_awake(void);
bool battery_activate(void);

#endif  // #ifndef _BATTERY_AWAKE_ACTIVATE_H_

/***********************************************************
 * end of file
 **********************************************************/
