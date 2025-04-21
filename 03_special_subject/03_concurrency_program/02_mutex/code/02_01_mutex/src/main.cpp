/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2024-09-01
 * |  V1.0.1    2025-04-21
 * ---------------------------------------
 * | @brief   : mutex 测试
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <unistd.h> // pause()头文件
#include <mutex>
#include <thread>

using std::cin;
using std::cout;
using std::endl;

std::mutex mtx;      // 全局互斥量
int shared_data = 0; // 共享数据

void increment()
{

    for (size_t i = 0; i < 5; i++)
    {
        mtx.lock();    // 尝试获取互斥量
        shared_data++; // 访问和修改共享数据
        cout << "Thread " << std::this_thread::get_id() << " incremented shared_data to " << shared_data << endl;
        mtx.unlock(); // 释放互斥量
    }
}

int main()
{
    printf("--------------------begain-------------------\n");

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_data: " << shared_data << std::endl;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
