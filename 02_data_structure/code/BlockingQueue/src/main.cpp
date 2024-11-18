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
#include <pthread.h>
#include <cstdio>
#include <string>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

int ticket = 1000;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  // 全局 pthread_cond_t 变量





using namespace std;

void * GetTicket(void * args)
{
    string name = static_cast<const char *>(args);
    while (true) {
        pthread_mutex_lock(&lock);
        // 线程进来都先排队
        pthread_cond_wait(&cond, &lock);  // 为什么要有lock,后面就说
        if (ticket > 0) {
            usleep(1000);
            cout << name << " 正在进行抢票: " << ticket << endl;
            ticket--;
            pthread_mutex_unlock(&lock);
        } else {
            pthread_mutex_unlock(&lock);
            break;
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

    pthread_t t[5];
    for (int i = 0; i < 5; ++i) {
        char *name = new char[64];
        snprintf(name, 64, "thread %d", i + 1);
        pthread_create(t + i, nullptr, GetTicket, name);
    }

    while (true) {
        sleep(1);
        // 主线程一秒唤醒一个线程
        pthread_cond_signal(&cond);
        std::cout << "main thread wakeup one thread..." << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(t[i], nullptr);
    }
    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
