// date_count.cpp : 定义控制台应用程序的入口点。
//定义一个结构体变量（包括年、月、日），计算该日在本年中为第几天？（注意考虑闰年问题）

#include "stdafx.h"
#include<iostream>
#include<process.h>
using namespace std;
 
struct Date
{
    int year;
    int month;
    int date;
}dat;
 
int IsLeapYear(int year)
{
    return (year%4==0 && year%100!=0)||(year%400==0);
}
 
int main(void)
{
    cout<<"输入年 月 日"<<endl;
    cin>>dat.year>>dat.month>>dat.date;
   
    int date = dat.date;
 
    switch(dat.month-1)
    {
    case 11:         //如果去除了case对应的break，则不会退出switch而运行到别的支路里去
        date += 30;
    case 10:
        date += 31;
    case 9:
        date += 30;
    case 8:
        date += 31;
    case 7:
        date += 31;  
    case 6:
        date += 30;
    case 5:
        date += 31;
    case 4:           
        date += 30;
    case 3:       
        date += 31;
    case 2:
        date += IsLeapYear(dat.year)+28;
    case 1:
        date += 31;
    }
   
    cout<<"第"<<date<<"天"<<endl;
    cout<<"星期"<<(date-4)%8<<endl;//有错误
	system("pause");
    return 0;
}
 
