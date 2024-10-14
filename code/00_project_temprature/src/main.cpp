/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream.h>  //包含输入/输出头文件
#include <stdio.h>     //包含C语言的库函数头文件
#include <string.h>    //包含字符串处理头文件

#include "XXX.h"

using std::cin;
using std::cout;
using std::endl;
/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - cmd 命令码
 * |           - dataPtr 发送的数据
 * |           - Len 发送的数据长度
 * | @return :
 * --------------
 * | @brief  : 发送请求到智能电池
 * |           通过串口2发送
 ******************************************************************************/
int main()
{
    printf("----------------begain------------------\n");
    uint8_t array[10] = {0x00, 0x08, 0xA5, 0x21, 0x00, 0x08, 0xA5, 0x21, 0x00, 0x08}; //AEA417BD
    uint32_t result1 = 0;
    uint32_t result2 = 0;
    printf("result1 :%8X\r\n", result1);
    printf("result2 :%8X\r\n", result2);

    result1 = CRC32(0, array, 10);

    printf("result1 :%8X\r\n", result1);
    printf("result2 :%8X\r\n", result2);

    result2 = calcMsgCRC(array, 10);

    printf("result1 :%8X\r\n", result1);
    printf("result2 :%8X\r\n", result2);

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
