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


#include <unistd.h>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

void pauseThread(int n)
{
    sleep(n);
    std::cout << "pause of " << n << " seconds ended" << std::endl;
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

    cout << "Run Main Thread" << endl;

    cout << "spawing 3 threads..." << endl;
    std::thread t1(pauseThread, 5);   // 线程这时候就已经开始启动
    std::thread t2(pauseThread, 10);  // 线程这时候就已经开始启动
    std::thread t3(pauseThread, 15);  // 线程这时候就已经开始启动
    cout << "Done spawning threads. Now wait for them to join: " << endl;
    t1.join();
    t2.join();
    t3.join();
    // 等待 threads 结束
    cout << "All all threads finished !" << endl;

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

