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
#include <mutex>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;

std::mutex mtx;       // 全局互斥量
// int shared_data = 0;  // 共享数据
int count1 = 1;
int count2 = 1;

void running_5_times(int count)
{
    for (size_t i = 0; i < 5; i++) {
        count++;
        cout << "Thread " << std::this_thread::get_id() << "running" << count << "times" << endl;
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void running1()
{
    mtx.lock();  // 尝试获取互斥量
    running_5_times(count1);
    running_5_times(count1);
    mtx.unlock();  // 释放互斥量
}

void running2()
{

    running_5_times(count2);

    mtx.lock();  // 尝试获取互斥量
    // 等待释放互斥量
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx.unlock();  // 释放互斥量

    running_5_times(count2);
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

    std::thread t1(running1);
    std::thread t2(running2);

    t1.join();
    t2.join();

    cout << "main function running" << endl;

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
