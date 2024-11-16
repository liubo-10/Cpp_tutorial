/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <thread>    //必须包含<thread>头文件

using std::cin;
using std::cout;
using std::endl;

void threadFunctionA()
{
    std::cout << "Run New thread: 1" << std::endl;
}
void threadFunctionB(int n)
{
    std::cout << "Run New thread: " << n << std::endl;
}

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
    printf("----------------begain------------------\n");

    std::cout << "Run Main Thread" << std::endl;

    std::thread newThread1(threadFunctionA);
    std::thread newThread2(threadFunctionB, 2);

    newThread1.join();
    newThread2.join();
    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
