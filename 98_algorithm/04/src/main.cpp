/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-01
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;

// 输入一个10进制正整数，然后输出它所对应的八进制数
// 示例1:输入10输出12
int D_to_O(int num)
{
    int power  = 1;
    int high   = num / 8;
    int low    = num % 8;
    int result = low;

    while (high > 8) {
        low  = (high % 8) * 10 * power + low;
        high = high / 8;
        power++;
    }

    result = high * power * 10 + low;
    return result;
}

int main()
{
    printf("--------------------begain-------------------\n");

    cout << D_to_O(7) << endl;
    cout << D_to_O(15) << endl;
    cout << D_to_O(585) << endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
