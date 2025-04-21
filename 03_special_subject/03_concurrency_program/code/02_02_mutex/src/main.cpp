/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream> // 包含输入和输出操作
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <stdlib.h>
#include <mutex>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::mutex;

mutex mtx; // 全局互斥量
// int shared_data = 0;  // 共享数据
int count1 = 0;
int count2 = 0;

void running_5_times(int& count)
{
    for (size_t i = 0; i < 5; i++) {
        count++;
        cout << "Thread " << std::this_thread::get_id() << " running " << count << " times" << endl;
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::seconds(1));
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

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int number;
mutex mutex_number;

const int MAXNUM = 10;

// 打印奇数
void add_1()
{
    while (1)
    {
        mutex_number.lock();
        if (number >= MAXNUM)
        {
            mutex_number.unlock();
            break;
        }
        if (number % 2 == 0)
        {
            number++;
            cout << "mythread_1: " << number << endl; // 输出
        }

        mutex_number.unlock();
    }
    cout << "mythread_1 finish" << endl; // mythread_1完成
}

// 打印偶数
void add_2()
{
    while (1)
    {
        mutex_number.lock();

        if (number >= MAXNUM)
        {
            mutex_number.unlock();
            break;
        }
        if (number % 2 == 1)
        {
            number++;
            cout << "mythread_2: " << number << endl; // 输出
        }

        mutex_number.unlock();
    }
    cout << "mythread_2 finish" << endl; // mythread_2完成
}

int main()
{
    number = 0;

    cout << endl
         << "Create and Start!" << endl;

    thread mythread_1(add_1);
    thread mythread_2(add_2);

    mythread_1.join();
    mythread_2.join();

    cout << endl
         << "Finish and Exit!" << endl;
    return 0;
}
