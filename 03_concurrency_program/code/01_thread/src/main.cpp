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

void threadFunctionA()
{
    cout << "Run New thread: 1" << endl;
}
void threadFunctionB(int n)
{
    cout << "Run New thread: " << n << endl;
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

    /*****************1.使用函数指针启动线程********************/

    // 函数指针可以是可调用对象，传递给 std::thread 构造函数以初始化线程。
    void foo(param){...}  // The parameters to the function are put after the comma
    std::thread thread_obj(foo, params);
    /********************************************************/


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








void pauseThread(int n)
{
    sleep(n);
    std::cout << "pause of " << n << " seconds ended" << std::endl;
}
int main()
{
    cout << "spawing 3 threads..." << endl;
    std::thread t1(pauseThread, 1);
    std::thread t2(pauseThread, 2);
    std::thread t3(pauseThread, 3);
    cout << "Done spawning threads. Now wait for them to join: " << endl;
    t1.join();
    t2.join();
    t3.join();
    cout << "All threads joined!" << endl;
    return 0;
}


