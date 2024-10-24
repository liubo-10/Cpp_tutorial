/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入/输出头文件 std::cout
#include <chrono>    // std::chrono::seconds, std::chrono::milliseconds
                     // std::chrono::duration_cast
#include <ratio>

using std::cin;
using std::cout;
using std::endl;

using std::ratio;
using std::chrono::hours;         // 以秒为单位的时间长度
using std::chrono::seconds;       // 以秒为单位的时间长度
using std::chrono::milliseconds;  // 以毫秒为单位的时间长度
using std::chrono::microseconds;  // 以微秒为单位的时间长度
using std::chrono::nanoseconds;   // 以纳秒为单位的时间长度
using std::chrono::duration;
using std::chrono::duration_cast;

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

    printf("\n自定义duration测试---------------------------------\n");

    duration<int, ratio<1, 25>> time1(2);  // 1/25*2秒
    cout << "duration (in periods) time1: ";
    cout << time1.count() << " 1/25秒." << endl;

    duration<double, ratio<1, 25>> time2(2.5);  // 1/25*2.5秒
    cout << "duration (in periods) time2: ";
    cout << time2.count() << " 1/25秒." << endl;

    printf("\ncount()函数测试---------------------------------\n");
    // duration 成员函数count(),用来表示这一段时间的长度
    milliseconds foo(1000);  // foo表示(1秒，1000微秒)长的时间段
    foo *= 60;
    cout << "duration (in periods) foo: ";
    cout << foo.count() << " milliseconds." << endl;

    seconds twentySeconds(20);       // 20秒
    cout << "duration (in periods) twentySeconds: ";
    cout << twentySeconds.count() << " seconds." << endl;

    hours aDay(24);                  // 24小时
    cout << "duration (in periods) aDay: ";
    cout << aDay.count() << " hours." << endl;

    milliseconds oneMillisecond(1);  // 1毫秒
    cout << "duration (in periods) oneMillisecond: ";
    cout << oneMillisecond.count() << " milliseconds." << endl;

    printf("\nduration的成员period测试---------------------------------\n");
    // den表示分母，num表示分子，ratio 的基本单位是秒
    // milliseconds::period::num=1,milliseconds::period::den = 1000;
    // num/den表示千分之一秒
    // 同理hours::period::num = 3600;hours::period::den = 1;最好用作比例
    cout << "milliseconds::period::num: ";
    cout << milliseconds::period::num << endl;

    cout << "milliseconds::period::den: ";
    cout << milliseconds::period::den << endl;


    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}



/*****************************************************************************
 * end of file
 ******************************************************************************/

