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

#include <iostream>  // 包含输入和输出操作

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    printf("--------------------begain-------------------\n");
    /**
     * write your code here 
     **/

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

// malloc的使用
#define _CRT_SECURE_NO_WARNINGS 1
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int* str = 0;
    int* p = 0;
    str = (int*)malloc(10 * sizeof(int));  // 开辟十个整型空间
    if (NULL == str) {
        printf("%s\n", strerror(errno));  // 若开辟失败
        // 使用报错函数strerror（errno）    要引用头文件<string.h>
    } else {
        p = str;
    }
    free(p);
    p = NULL;
    return 0;
}

