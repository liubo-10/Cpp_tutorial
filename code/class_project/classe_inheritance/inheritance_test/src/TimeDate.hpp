/*****************************************************************************
 * | @file    : TimeDate.hpp
 * | @author  : liubo
 * | @version : V1.0.0     |V1.0.1     |V1.0.2
 * | @date    : 2024-01-05 |2024-08-22 |2024-09-01
 * --------------
 * | @brief   : CPP template
 ******************************************************************************/
#ifndef _TIMEDATE_HPP_
#define _TIMEDATE_HPP_

#include <iostream.h>  //包含输入/输出头文件

typedef char string80[80];  // 重定义字符串数据类型

class Date  // 定义类
{
   public:                     // 定义公有成员
    Date() {}                  // 声明构造函数
    Date(int y, int m, int d)  // 重载构造函数
    {
        SetDate(y, m, d);  // 调用函数
    }
    void SetDate(int y, int m, int d)  // 定义公有成员函数
    {
        Year = y;  // 给成员变量赋初值
        Month = m;
        Day = d;
    }
    string80& GetStringDate(string80& Date)  // 定义公有成员函数
    {
        sprintf(Date, "%d/%d/%d", Year, Month, Day);  // 输出字符串
        return Date;                                  // 返回结果
    }

   protected:              // 定义保护成员
    int Year, Month, Day;  // 定义整型变量
};

class Time  // 定义类Time
{
   public:                     // 定义公有成员
    Time() {}                  // 定义构造函数
    Time(int h, int m, int s)  // 重载构造函数
    {
        SetTime(h, m, s);  // 调用设置时间汉化
    }
    void SetTime(int h, int m, int s)  // 定义公有成员函数
    {
        Hours = h;  // 给成员变量赋初值
        Minutes = m;
        Seconds = s;
    }
    string80& GetStringTime(string80& Time)  // 定义公有成员函数
    {
        sprintf(Time, "%d:%d:%d", Hours, Minutes, Seconds);
        // 输出字符串
        return Time;  // 返回结果
    }

   protected:                     // 定义保护成员
    int Hours, Minutes, Seconds;  // 定义整型变量
};

class TimeDate : public Date, public Time  // 定义派生类
{
   public:                  // 定义公有成员
    TimeDate() : Date() {}  // 声明派生类构造函数
    TimeDate(int y, int mo, int d, int h, int mi, int s) : Date(y, mo, d), Time(h, mi, s) {}  // 重载构造函数
    string80& GetStringDT(string80& DTstr)  // 定义派生类成员函数
    {
        sprintf(DTstr, "%d/%d/%d;%d:%d:%d", Year, Month, Day, Hours, Minutes,
                Seconds)   // 输出
            return DTstr;  // 返回结果
    }
};

#endif  // #ifndef _TIMEDATE_HPP_

/***********************************************************
 * end of file
 **********************************************************/
