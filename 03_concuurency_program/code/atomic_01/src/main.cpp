/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : 使用互斥量保证线程互斥
 ******************************************************************************/
#include <iostream>  // 包含输入/输出头文件
#include <stdio.h>   // 包含C语言的库函数头文件
#include <string.h>  // 包含字符串处理头文件
#include <thread>    // 多线程库 <thread>
#include <mutex>     // 互斥量库
#include <atomic>    // 原子操作库
#include <vector>    // 向量库
#include <chrono>    // 时间处理库

using std::cin;
using std::cout;
using std::endl;

long long globalCount = 0;
std::mutex globalMutex;

void ThreadFunction()
{
    std::lock_guard<std::mutex> lock(globalMutex);
    for (int i = 0; i < 100000; ++i) {
        globalCount += 1;
    }
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

    std::vector<std::thread> threads;

    std::chrono::system_clock::time_point startTime;
    startTime = std::chrono::system_clock::now();

    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(ThreadFunction));
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }
    std::chrono::system_clock::time_point endTime;
    endTime = std::chrono::system_clock::now();

    cout << "当前总数为:" << globalCount << endl;
    cout << "消耗时间为:" 
         << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
         << "毫秒" << endl;

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
