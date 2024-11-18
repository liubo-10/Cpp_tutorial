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
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

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





int shared_data = 0;
pthread_mutex_t mutex;

void *threadFoo(void *arg)
{
    pthread_mutex_lock(&mutex);  // 加锁
    while (1) {
        shared_data++;
        printf("threadFoo:shared_data=%d\n", shared_data);
        if (shared_data == 10) {
            pthread_mutex_unlock(&mutex);  // 执行完之后解锁
            pthread_exit(NULL);
        }
        sleep(1);
    }
}
void *threadBar(void *arg)
{
    pthread_mutex_lock(&mutex);  // 加锁
    while (1) {
        shared_data++;
        printf("___threadBar:shared_data=%d\n", shared_data);
        if (shared_data == 20) {
            pthread_mutex_unlock(&mutex);  // 执行完之后解锁
            pthread_exit(NULL);
        }
        sleep(1);
    }
}

int main()
{
    pthread_t threadID1;
    pthread_t threadID2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&threadID1, NULL, (void *)threadFoo, NULL);
    pthread_create(&threadID2, NULL, (void *)threadBar, NULL);
    pthread_join(threadID1, NULL);
    pthread_join(threadID2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
