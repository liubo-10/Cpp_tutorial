* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa

# C++时间处理03--chrono中的durations

chrono是在std下，属于C++11的标准，它的头文件为#include\<chrono\>，是一个处理时间的元素。主要包括三个概念：

1. Durantions：时间段
2. Time points：时间点
3. Clocks：包括system_clock(系统时钟),steady_clock（稳定时钟）;high_resolution_clock（高精度时钟）;



## 一、时间段 Durations

duration表示一段时间间隔，用来记录时间长度，可以表示几秒、几分钟、几个小时的时间间隔。

### 1.1、duration的原型

duration的原型如下：

```c++
// 定义于头文件 <chrono>
/// `chrono::duration` represents a distance between two points in time
template<typename _Rep, typename _Period = ratio<1>>
struct duration;
```

- Rep：这是一个数值类型，用来表示时间段所经历的滴答（tick）数。**若 Rep 是浮点数，则 duration 能使用小数描述时钟周期的数目**。
- Period：表示时钟的周期，为ratio类型。默认类型以秒为单位。
- 可以使用内部的.count函数对它进行使用。



### 1.2、ratio的原型

ratio的原型如下：

```c++
// 定义于头文件 <ratio>
template <intmax_t _Num, intmax_t _Den = 1>
struct ratio

```

ratio类表示每个时钟周期的秒数，其中第一个模板参数Num代表分子，Denom代表分母，该分母值默认为1，因此，ratio代表的是一个分子除以分母的数值，比如：ratio<2>代表一个时钟周期是2秒，ratio<60>代表一分钟，ratio<6060>代表一个小时，ratio<6060*24>代表一天。而ratio<1,1000>代表的是1/1000秒，也就是1毫秒，ratio<1,1000000>代表一微秒，ratio<1,1000000000>代表一纳秒，ratio<1, 30>代表三十分之一秒。





```c++
duration<int, ratio<1, 25>> time1(2);  // 1/25*2秒
cout << "duration (in periods) time1: ";
cout << time1.count() << " 1/25秒." << endl;

duration<double, ratio<1, 25>> time2(2.5);  // 1/25*2.5秒
cout << "duration (in periods) time2: ";
cout << time2.count() << " 1/25秒." << endl;
```

输出结果

```tex
duration (in periods) time1: 2 1/25秒.
duration (in periods) time2: 2.5 1/25秒.
```





### 1.3、常用的ratio

常用的ratio在文件\<ratio\>定义如下：

```c++
typedef ratio<1,   1000000000000000000> atto;  // attosecond 阿托秒 10的18次方
typedef ratio<1,      1000000000000000> femto; // femtosecond 飞秒 10的15次方
typedef ratio<1,         1000000000000> pico;  // picosecond 皮秒 10的12次方
typedef ratio<1,            1000000000> nano;  // nanosecond 纳秒 10的9次方
typedef ratio<1,               1000000> micro; // microsecond 微秒 10的6次方
typedef ratio<1,                  1000> milli; // millisecond 毫秒 10的3次方
typedef ratio<1,                   100> centi; // centisecond 厘秒
typedef ratio<1,                    10> deci;  // decisecond  分秒
typedef ratio<10,                    1> deca;
typedef ratio<100,                   1> hecto;
typedef ratio<1000,                  1> kilo;
typedef ratio<1000000,               1> mega;
typedef ratio<1000000000,            1> giga;
typedef ratio<1000000000000,         1> tera;
typedef ratio<1000000000000000,      1> peta;
typedef ratio<1000000000000000000,   1> exa;
```



### 1.4、常用的duration

ratio配合duration定义常用时间单位

常用的duration在文件\<ratio\>定义如下：

```c++
using nanoseconds	= duration<_GLIBCXX_CHRONO_INT64_T, nano>;    // 纳秒
using microseconds	= duration<_GLIBCXX_CHRONO_INT64_T, micro>;   // 微秒
using milliseconds	= duration<_GLIBCXX_CHRONO_INT64_T, milli>;   // 毫秒
using seconds	= duration<_GLIBCXX_CHRONO_INT64_T>;              // 秒
using minutes	= duration<_GLIBCXX_CHRONO_INT64_T, ratio< 60>>;  // 分钟
using hours		= duration<_GLIBCXX_CHRONO_INT64_T, ratio<3600>>; // 小时
```



```c++
chrono::seconds      twentySeconds(20); //20秒
chrono::hours        aDay(24);          //24小时
chrono::milliseconds oneMillisecond(1); //1毫秒
```



## 二、duration的成员



### 2.1、count函数

duration类还提供了获取时间间隔的时钟周期数的方法count()

函数原型如下：

```c++
constexpr rep
count() const
{ return __r; }
```



示例：

```c++
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
```



输出结果

```tex
duration (in periods) foo: 60000 milliseconds.
duration (in periods) twentySeconds: 20 seconds.
duration (in periods) aDay: 24 hours.
duration (in periods) oneMillisecond: 1 milliseconds.
```





### 2.2、duration的算术运算

duration可以进行的大多数算术运算。

如下：

- 计算两个duration的和、差、积和商
- 加减tick，或加减其他duration
- 比较两个duration的大小



注意事项：duration的加减运算有一定的规则，当两个duration时钟周期不相同的时候，会先统一成一种时钟，然后再进行算术运算，统一的规则如下：假设有ratio<x1,y1> 和 ratio<x2,y2>两个时钟周期，首先需要求出x1，x2的最大公约数X，然后求出y1，y2的最小公倍数Y，统一之后的时钟周期ratio为ratio<X,Y>。






### 2.3、duration的成员period

在duration的成员period中，den表示分母，num表示分子，ratio 的基本单位是秒

比如milliseconds::period::num=1,milliseconds::period::den = 1000

num/den表示千分之一秒。同理hours::period::num = 3600，hours::period::den = 1



```c++
cout << "milliseconds::period::num: ";
cout << milliseconds::period::num << endl;

cout << "milliseconds::period::den: ";
cout << milliseconds::period::den << endl;
```



```tex
milliseconds::period::num: 1
milliseconds::period::den: 1000
```



综合案例

```c++
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

```





## 三、总结

以上就是今天要讲的内容



## 四、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、https://blog.csdn.net/f593256/article/details/134833814

二、















---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---