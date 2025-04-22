/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2024-09-01
 * |  V1.0.0    2025-04-22
 * ---------------------------------------
 * | @brief   : tread join test
 ******************************************************************************/
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件

#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;

void pause_thread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "暂停 " << n << " 秒结束\n";
}

int main()
{
    printf("--------------------begain-------------------\n");

    cout << "Run Main Thread" << endl;

    std::cout << "生成三个线程...\n";
    std::thread t1(pause_thread, 1); // 线程这时候就已经开始启动
    std::thread t2(pause_thread, 2); // 线程这时候就已经开始启动
    std::thread t3(pause_thread, 3); // 线程这时候就已经开始启动

    std::cout << "线程已经生成，等待分离...:\n";
    t1.detach();
    t2.detach();
    t3.detach();

    std::cout << "所有线程分离!\n";

    // 给被分离线程5秒时间完成，但线程不一定完成!
    pause_thread(5); // 暂停5秒

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
