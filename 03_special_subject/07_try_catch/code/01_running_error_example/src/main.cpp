/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2025-01-17
 * --------------
 * | @brief   : 运行故障举例
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

#include <iostream>  // 包含输入和输出操作

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - XXX XXX
 * |           - XXX XXX
 * |           - XXX XXX
 * | @return :
 * --------------
 * | @brief  : XXX
 * |           XXX
 ******************************************************************************/
int main()
{
    printf("--------------------begain-------------------\n");

    string str = "http://hhhhhhhh.net";
    char ch1 = str[100];  // 下标越界，ch1为垃圾值
    cout << ch1 << endl;
    char ch2 = str.at(100);  // 下标越界，抛出异常
    cout << ch2 << endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/



