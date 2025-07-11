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

// 输入10个整数，对其进行排序输出
// 示例1:输入9 8 7 6 5 4 3 2 1 0 输出 0 1 2 3 4 5 6 7 8 9
// 589 27 0 9 26

int* sort(int array[], int size)
{
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            int temp = 0;
            if (array[j] > array[j + 1]) {
                temp         = array[j + 1];
                array[j + 1] = array[j];
                array[j]     = temp;
            }
        }
    }
    return array;
}

int main()
{
    printf("--------------------begain-------------------\n");

    int arry[] = {589, 27, 0, 9, 26};

    sort(arry, 5);
    for (int i = 0; i < 5; i++) {
        cout << arry[i] << " ";
    }
    cout << "\n";

    int arry1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    sort(arry1, 10);
    for (int i = 0; i < 10; i++) {
        cout << arry1[i] << " ";
    }
    cout << "\n";

    int arry2[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};

    sort(arry2, 11);
    for (int i = 0; i < 11; i++) {
        cout << arry2[i] << " ";
    }
    cout << "\n";

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
