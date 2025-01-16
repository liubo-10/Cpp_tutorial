/*****************************************************************************
 * | @file    : space_input.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-01-28
 * --------------
 * | @brief   : iosream deal with space
 ******************************************************************************/

#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

#include <iostream>  // 包含输入和输出操作

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    printf("--------------------begain-------------------\n");
    cout << "\n----------------空格输入 测试------------------" << endl;
    float a;
    int i1, i2;
    char ch1, ch2;
    cin >> i1 >> a >> i2 >> ch1 >> ch2;

    cout << "i1:" << i1 << "  a:" << a << "  i2:" << i2 << "  ch1:" << ch1 << "  ch2:" << ch2 << endl;
    // 输入：34  5.678  1a  b<CR>
    // 输出：i1:34  a:5.678  i2:1  ch1:a  ch2:b

    printf("--------------------end----------------------\n");
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
