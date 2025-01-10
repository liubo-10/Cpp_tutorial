/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-11-12
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等

#include <time.h>

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

    time_t my_time;
    time(&my_time); /*获取从1970至当前时间过了多少秒，存为time_t类型*/
    printf("my_time = %ld \n", my_time);

    char* date1;
    date1 = ctime(&my_time);  // 将秒数转化成字符串格式，输出：Fri Nov  8 11:24:34 2024
    printf("\nctime swich time_t to char*\n");
    printf("%s", date1);

    struct tm* p;
    p = localtime(&my_time);  // 用localtime将秒数转化为struct tm结构体
    printf("\nlocaltime swich time_t to struct tm\n");
    printf("%d/%d/%d %02d:%02d:%02d\n",
    1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);  // 2024/11/8 11:24:34

    struct tm* p1;
    p1 = gmtime(&my_time);
    printf("\ngmtime swich time_t to struct tm\n");
    printf("%d/%d/%d %02d:%02d:%02d\n",
    1900 + p1->tm_year, 1 + p1->tm_mon, p1->tm_mday, p1->tm_hour, p1->tm_min, p1->tm_sec);

    // 输出星期
    char* wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("%s\n", wday[p->tm_wday]);

    char* date2;
    date2 = asctime(p);  // 将struct tm转化成字符串格式和ctime输出格式一致，输出：Fri Nov  8 11:24:34 2024
    printf("\nasctime swich struct tm to char*\n");
    printf("%s", date2);

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
