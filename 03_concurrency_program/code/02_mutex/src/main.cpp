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
int shared_data = 0;  // 共享数据


void increment()
{
    for (size_t i = 0; i < 5; i++) {
        mtx.lock();     // 尝试获取互斥量
        ++shared_data;  // 访问和修改共享数据
        cout << "Thread " << std::this_thread::get_id() << " incremented shared_data to " << shared_data << endl;
        mtx.unlock();  // 释放互斥量

        cout << "Thread " << std::this_thread::get_id() << " unlock" << shared_data << endl;

        for (int count = 0; count++; count < 3) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "Thread " << std::this_thread::get_id() << "run "<< count << endl;
        }
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

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_data: " << shared_data << std::endl;

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
