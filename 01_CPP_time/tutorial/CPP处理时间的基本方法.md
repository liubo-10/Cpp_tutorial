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

# CPP处理时间的基本方法
在time.h文件中包含了CPP对时间处理的基本方法



## time_t

变量类型 time_t，通常是一个长整型（long int），用于表示从特定参考点（通常是 1970年1月1日00:00:00 UTC）经过的秒数。被广泛用作时间戳。



## time()

函数原型

```c++
time_t time(time_t *t);
```

取得从1970年1月1日至今的秒数。



示例

```c++
time_t my_time;
time(&my_time); /*获取从1970至当前时间过了多少秒，存为time_t类型*/
printf("my_time = %ld \n", my_time);
```

结果

```tex
my_time = 1731036274 
```



## ctime()

函数原型

```c++
　char *ctime(const time_t *timep);
```

将 time_t 类型转换为字符串格式的时间，传入一个time_t类型变量的地址，返回一个字符数组指针，优点是可以直接按字符串输出，缺点是不能自行控制输出格式。



示例

```c++
time_t my_time;
char* data;
data = ctime(&my_time);
printf("%s", data);  // 用ctime将秒数转化成字符串格式，输出：Fri Nov  8 11:24:34 2024
```

结果

```tex
Fri Nov  8 11:24:34 2024
```



## struct tm

结构体定义

```c++
struct tm
{ 
  int  tm_sec;  	/* Seconds: 0-60 (to accommodate leap seconds) */
  int  tm_min;  	/* Minutes: 0-59 */
  int  tm_hour; 	/* Hours since midnight: 0-23 */
  int  tm_mday; 	/* Day of the month: 1-31 */
  int  tm_mon;  	/* Months *since* January: 0-11 */
  int  tm_year; 	/* Years since 1900 */
  int  tm_wday; 	/* Days since Sunday (0-6) */
  int  tm_yday; 	/* Days since Jan. 1: 0-365 */
  int  tm_isdst;	/* +1=Daylight Savings Time, 0=No DST, -1=unknown */
};

```

用stuct tm结构体，可自己改变格式





## localtime()

函数原型

```c++
stuct tm* localtime(const time_t *timep);
```

用于将时间戳（time_t 类型）转换为本地时间的结构体(struct tm)。

它接受一个指向 time_t 类型的指针作为参数，并返回一个指向 tm 结构体的指针

优点是可以自行控制输出格式，缺点是不能直接当作字符串输出，得用指针访问结构体内部输出。



示例

```c++
struct tm* p;
p = localtime(&my_time);  // 用localtime将秒数转化为struct tm结构体

printf("%d/%d/%d %02d:%02d:%02d\n",
1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
```

结果

```tex
2024/11/12 17:14:07
```



## gmtime()

函数原型

```c++
struct tm* gmtime(const time_t *timep);
```

用于将时间戳（time_t 类型）转换为本地时间的结构体(struct tm)。

它接受一个指向 time_t 类型的指针作为参数，并返回一个指向 tm 结构体的指针

优点是可以自行控制输出格式，缺点是不能直接当作字符串输出，得用指针访问结构体内部输出。
和localtime类似，区别是gmtime不加地方时。




























## asctime()

函数原型

```c++
char * asctime(const struct tm* timeptr);
```

将struct tm结构体转化为字符串,传入一个struct tm结构体类型的指针，返回一个字符数组指针。

和ctime输出格式一致














































https://blog.csdn.net/weixin_44032878/article/details/87939039?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522398D6A1D-FC4C-4CC3-920A-07B92FC3856C%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=398D6A1D-FC4C-4CC3-920A-07B92FC3856C&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-87939039-null-null.142^v100^pc_search_result_base4&utm_term=time_t&spm=1018.2226.3001.4187







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
