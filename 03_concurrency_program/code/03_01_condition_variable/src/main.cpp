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
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

std::queue<int> g_queue;
std::mutex g_mutex;
std::condition_variable g_cv;

void producer()
{
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::unique_lock<std::mutex> lock(g_mutex);
        g_queue.push(i);

        std::cout << "Producer: " << i << std::endl;

        // 通知等待中的消费者线程
        g_cv.notify_one();
    }
}

void consumer(int id)
{
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(g_mutex);

        // 等待条件满足
        g_cv.wait(lock, [] { return !g_queue.empty(); });

        int value = g_queue.front();
        g_queue.pop();

        std::cout << "Consumer " << id << ": " << value << std::endl;
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

    std::thread t1(producer);
    std::thread t2(consumer, 1);
    std::thread t3(consumer, 2);

    t1.join();
    t2.join();
    t3.join();
    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
