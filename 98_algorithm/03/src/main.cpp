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

// 输入n个整数,存放在数组a[1]至a[n]中，输出最大数所在位置(n≤1000)
// 输入描述：第一行，数的个数n;第二行，n个正整数，每个数在232−1之内。
// 示例1:输入589 27 0 9 26输出1
int biggest_index(int arr[], int size)
{
    int max_val = arr[0];
    int max_id  = 0;
    for (int i = 1; i < size; i++) {
        if (max_val < arr[i]) {
            max_val = arr[i];
            max_id = i;
        }
    }
    return max_id + 1;
}

int main()
{
    printf("--------------------begain-------------------\n");

    int arry[] = {589, 27 ,0, 9 ,26};

    cout << biggest_index(arry, 5) << endl;

    int arry1[] = {1, 2, 3, 4, 5};

    cout << biggest_index(arry1, 5) << endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
