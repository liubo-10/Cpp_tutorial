/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  //包含输入/输出头文件
#include <stdio.h>     //包含C语言的库函数头文件
#include <string.h>    //包含字符串处理头文件

#include "TimeDate.hpp"

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
    TimeDate date1, date2(2008, 6, 5, 10, 15, 05);  // 创建派生类对象
    string80 DemoStr;                               // 定义字符串数据类型
    date1.SetDate(2008, 9, 10);                     // 调用基类成员函数
    date1.SetTime(19, 07, 30);                      // 调用设置时间函数
    cout << "The date1 date and time is:" << date1.GetStringDT(DemoStr) << endl;
    // 调用派生类成员函数
    cout << "The date1 date is:" << date1.GetStringDate(DemoStr) << endl;
    // 调用成员函数输出结果
    cout << "The date1 time is:" << date1.GetStringTime(DemoStr) << endl;
    cout << "The date2 date and time is:" << date2.GetStringDT(DemoStr) << endl;

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
