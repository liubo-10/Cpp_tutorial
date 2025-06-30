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

// 计算出k以内最大的10个能被13或17整除的自然数之和
// 示例1:输入500输出4622
int ten_sum(int k)
{
    int num    = 0;
    int result = 0;

    while (k > 2 && num < 10) {
        if (k % 13 == 0 || k % 17 == 0) {
            result += k;
            num++;
        }
        k--;
    }
    return result;
}

int main()
{
    printf("--------------------begain-------------------\n");
    
    int sum = 0;
    sum = ten_sum(500);
    cout << sum << endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
