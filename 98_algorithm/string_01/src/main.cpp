/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-01
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 示例1:输入 Hello 输出HELLO
// 示例2:输入 TesT8 输出TEST8
// 示例3:输入 12345abcde 输出12345ABCDE
string char_change(string str)
{
    int size = str.size();

    for (int i = 0; i < size; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    return str;
}

int main()
{
    printf("--------------------begain-------------------\n");
    string s = "Hello";

    cout << char_change(s);

    s = "TesT8";

    cout << char_change(s);

    s = "12345abcde";

    cout << char_change(s);

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

    /*****************************************************************************
     * end of file
     ******************************************************************************/
