/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-11-28
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等

#include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
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


    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

#include <iostream>
#include <condition_variable>

using namespace std;

mutex wait_mutex;
condition_variable wait_condition_variable;
bool ready = false;

// 等待线程函数
void wait_thread_func()
{
    // 等待通知再继续执行
    unique_lock<mutex> lock(wait_mutex);
    cout << "等待线程(" << this_thread::get_id() << "): 开始等待通知..." << endl;
    wait_condition_variable.wait(lock, [] {
        bool state = ready;
        cout << "wait执行中(判断条件后,等待通知前)" << endl;  // 模拟“wait执行中”
        this_thread::sleep_for(3s);
        return state;
    });
    cout << "等待线程(" << this_thread::get_id() << "): 继续执行代码..." << endl;
}

int main()
{
    thread wait_thread(wait_thread_func);

    this_thread::sleep_for(1s);  // 模拟“wait执行中”进行通知

    unique_lock<mutex> lock(wait_mutex);
    cout << "通知线程(" << this_thread::get_id() << "): 开始通知等待线程..." << endl;
    ready = true;
    lock.unlock();  // 不解锁的话，等待线程无法获得锁，则会进入死锁
    wait_condition_variable.notify_one();

    wait_thread.join();
    cout << "--- main结束 ---" << endl;
}
