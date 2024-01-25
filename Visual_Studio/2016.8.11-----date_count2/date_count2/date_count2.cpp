//实现判断一个输入日期是星期几，是一年中的第几天

#include "stdafx.h"
#include<iostream>
#include<process.h>
using namespace std;  
  
struct time  
{  
int year;  
int month;  
int day;  
unsigned int weekday;  
};  
  
void initialtime(time & t);//输入初始化时间  
void Show(time & t);//显示时间信息  
int Weekdaycount(time & t);//计算当日是星期几  
int Daycount(time & t);//计算当日是第公元多少天  
int Daysyearcount(time & t);//计算当日是该年的第多少天  
bool isleapyear(time & t);//判断该年是不是闰年  
bool check(time &t);//检查时间格式是否正确  
  
int main()  
{  
time t;  
initialtime(t);  
Show(t);  
system("pause");
return 0;  
}  
  
bool check(time &t)  
{  
if (t.year <= 0 || (t.month <= 0 || t.month>12) || t.day <= 0) return false;  
else{  
if ((t.month == 1 || t.month == 3 || t.month == 5 || t.month == 7  
|| t.month == 8 || t.month == 10 || t.month == 12) && t.day > 31)return false;  
else  
{  
if ((t.month == 4 || t.month == 6 || t.month == 9 || t.month == 11  
) && t.day > 30)return false;  
else  
{  
if (t.month == 2) {  
if (isleapyear(t)) {  
if (t.day > 29)return false; else return true;  
}  
else  
{  
if (t.day > 28)return false; else return true;  
}  
}  
}  
}  
}  
}  
void initialtime(time & t)  
{  
cout << "Enter the time (year,month,day):\n";  
cin >> t.year;  
cin.get();  
cin>> t.month;  
cin.get();  
cin >> t.day;  
cin.get();  
if (!check(t)){ cout << "Try again:\n"; initialtime(t); }  
else  
t.weekday = Weekdaycount(t);  
}  
void Show(time & t)  
{  
cout << "Year: " << t.year << "\t";  
cout << "Month: " << t.month << "\t";  
cout << "Day: " << t.day << "\t";  
cout << "Weekday: " << t.weekday << endl;  
cout << "This is a ";  
if (isleapyear(t))cout << "leap"; else cout << "nonleap";  
cout << " year.\n";  
cout << "Today is the " << Daysyearcount(t) << " days of the year.\n";  
}  
int Weekdaycount(time & t)  
{  
return Daycount(t) % 7;  
}  
int Daycount(time & t)  
{  
int days = 0;  
days = (t.year - 1) * 365 + (t.year - 1) / 4 - (t.year - 1) / 100  
+ (t.year - 1) / 400 + Daysyearcount(t);  
return days;  
}  
bool isleapyear(time & t)  
{  
if (t.year % 4 == 0 && t.year % 100 != 0) return true;//年是四的倍数而且不是100的倍数，是闰年  
if (t.year % 400 == 0)return true;  
else return false;  
}  
int Daysyearcount(time & t)  
{  
int days = 0;  
int mtemp = t.month - 1;  
while (mtemp > 0)  
{  
switch (mtemp)  
{  
case(1) :  
case(3) :   
case(5) :   
case(7) :   
case(8) :   
case(10) :   
case(12) :  
days += 31; break;  
case(4):  
case(6):  
case(9):   
case(11):  
days += 30; break;  
case(2) :  
days += 28; break;  
default:  
break;  
}  
--mtemp;  
}  
if (isleapyear(t))++days;//如果是闰年，再加上一天  
return days+t.day;//返回计算的天数加上当月的天数  
}  