/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

#include <exception>
#include <iostream>  // 包含输入和输出操作

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    printf("--------------------begain-------------------\n");

    string str = "http://c.linzeyu.net";

    try {
        char ch1 = str[100];
        cout << ch1 << endl;
    } catch (exception e) {
        cout << "[1]out of bound!" << endl;
    }
    try {
        char ch2 = str.at(100);
        cout << ch2 << endl;
    } catch (exception& e) {  // exception类位于<exception>头文件中
        cout << "[2]out of bound!" << endl;
    }

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
