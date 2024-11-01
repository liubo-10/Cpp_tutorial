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
// #include <ctime>  //将时间格式的数据转换成字符串

using std::cin;
using std::cout;
using std::endl;

// using namespace std::chrono;
using std::ratio;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::time_point;


using std::chrono::microseconds;  // 以微秒为单位的时间长度
using std::chrono::milliseconds;  // 以毫秒为单位的时间长度
using std::chrono::nanoseconds;   // 以纳秒为单位的时间长度
using std::chrono::seconds;       // 以秒为单位的时间长度
using std::chrono::hours;         // 以秒为单位的时间长度

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

    // 新纪元1970.1.1时间
    system_clock::time_point epoch;
    // 将获取的时间转换成time_t类型
    time_t tm2 = system_clock::to_time_t(epoch);
    cout << tm2 << endl;
    printf("------%d\n", tm2);
    // ctime()函数将time_t类型的时间转化成字符串格式,这个字符串自带换行符
    cout << "新纪元时间:      " << ctime(&tm2);

    system_clock::time_point endTime;
    endTime = system_clock::now();



        hours aDay(24);  // 24小时

    cout << "消耗时间为:" << duration_cast<milliseconds>(endTime - epoch).count()<< "毫秒" << endl;
    cout << "消耗时间为:" << duration_cast<seconds>(endTime - epoch).count()<< "秒" << endl;
    cout << "消耗时间为:" << duration_cast<hours>(endTime - epoch).count()<< "时" << endl;
    cout << "消耗时间为:" << duration_cast<hours>(endTime - epoch).count()<< "天" << endl;




    duration<int, ratio<60 * 60 * 24>> day(1);
    // 新纪元1970.1.1时间 + 1天
    system_clock::time_point ppt(day);

    cout << "消耗时间为:" << ppt.time_since_epoch().count() << "时" << endl;

    



    using dday = duration<int, ratio<60 * 60 * 24>>;
    // 新纪元1970.1.1时间 + 10天
    time_point<system_clock, dday> t(dday(10));

    //  获取系统的当前时间
    system_clock::time_point today = system_clock::now();

    // 转换为time_t时间类型
    time_t tm = system_clock::to_time_t(today);
    cout << "今天的日期是:    " << ctime(&tm);

    time_t tm1 = system_clock::to_time_t(today + day);
    cout << "明天的日期是:    " << ctime(&tm1);

    time_t tm3 = system_clock::to_time_t(ppt);
    cout << "新纪元时间+1天:  " << ctime(&tm3);

    time_t tm4 = system_clock::to_time_t(t);
    cout << "新纪元时间+10天: " << ctime(&tm4);

    printf("-----------------end-------------------\n");
    // getchar();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
