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

# chrono中的Clock
chrono库中提供了获取当前的系统时间的时钟类，包含的时钟一共有三种：

- system_clock：系统的时钟，系统的时钟可以修改，甚至可以网络对时，因此使用系统时间计算时间差可能不准。

- steady_clock：是固定的时钟，相当于秒表。开始计时后，时间只会增长并且不能修改，适合用于记录程序耗时
- high_resolution_clock：和时钟类 steady_clock 是等价的（是它的别名）。

在这些时钟类的内部有time_point、duration、Rep、Period等信息，基于这些信息来获取当前时间，以及实现time_t和time_point之间的相互转换。

### 时钟类成员类型 描述

rep 表示时钟周期次数的有符号算术类型
period 表示时钟计次周期的 std::ratio 类型
duration 时间间隔，可以表示负时长
time_point 表示在当前时钟里边记录的时间点

在使用chrono提供的时钟类的时候，不需要创建类对象，直接调用类的静态方法就可以得到想要的时间了。



## system_clock
具体来说，时钟类system_clock是一个系统范围的实时时钟。system_clock提供了对当前时间点time_point的访问，将得到时间点转换为time_t类型的时间对象，就可以基于这个时间对象获取到当前的时间信息了。

system_clock时钟类在底层源码中的定义如下：



```c++
struct system_clock { // wraps GetSystemTimePreciseAsFileTime/GetSystemTimeAsFileTime
    using rep                       = long long;
    using period                    = ratio<1, 10'000'000>; // 100 nanoseconds
    using duration                  = chrono::duration<rep, period>;
    using time_point                = chrono::time_point<system_clock>;
    static constexpr bool is_steady = false;

    _NODISCARD static time_point now() noexcept 
    { // get current time
        return time_point(duration(_Xtime_get_ticks()));
    }

    _NODISCARD static __time64_t to_time_t(const time_point& _Time) noexcept 
    { // convert to __time64_t
        return duration_cast<seconds>(_Time.time_since_epoch()).count();
    }

    _NODISCARD static time_point from_time_t(__time64_t _Tm) noexcept 
    { // convert from __time64_t
        return time_point{seconds{_Tm}};
    }
};

```









- rep：时钟周期次数是通过整形来记录的long long

- period：一个时钟周期是100纳秒ratio<1, 10’000’000>
- duration：时间间隔为rep*period纳秒chrono::duration<rep, period>
- time_point：时间点通过系统时钟做了初始化chrono::time_point<system_clock>，里面记录了新纪元时间点





另外还可以看到system_clock类一共提供了三个静态成员函数：

```c++
// 返回表示当前时间的时间点。
static std::chrono::time_point<std::chrono::system_clock> now() noexcept;
// 将 time_point 时间点类型转换为 std::time_t 类型
static std::time_t to_time_t( const time_point& t ) noexcept;
// 将 std::time_t 类型转换为 time_point 时间点类型
static std::chrono::system_clock::time_point from_time_t( std::time_t t ) noexcept;

```







































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
