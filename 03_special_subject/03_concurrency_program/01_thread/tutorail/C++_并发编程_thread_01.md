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
* 🚨 gdfgdshdfhfhygjtyu


> # C++_并发编程\_thread_01



# 一、thread是什么

多线程是一种功能，它允许并发执行程序的两个或多个部分，以最大限度地利用 CPU。这种程序的每个部分都称为线程。多线程支持是在 C++11 中引入的。在 C++11 之前，我们必须使用 POSIX 线程或库。虽然这个库完成了这项工作，但缺乏任何标准语言提供的功能集导致了严重的可移植性问题。C++ 11 取消了所有这些，并给了我们 std::thread。线程类和相关函数在头文件<thread\>中定义。

类thread表示单个执行线程。线程在构建关联的线程对象时立即开始执行。其定义用于观察和管理应用程序中的执行线程的对象。



包含头文件

```c++
#include <thread>
```

# thread构造函数

std::thread 是 C++ 中表示单个线程的线程类。要启动线程，我们只需要创建一个新的线程对象，并将要调用的执行代码（即可调用对象）传递到对象的构造函数中。



## 默认构造函数

```c++
thread() noexcept
```



## 初始化构造函数

```c++
template <class Fn, class... Args>
explicit thread (Fn&& fn, Args&&... args);
```

该函数使用可变参数模板来构造一个线程对象，用来代表一个新的可join的执行线程。这个执行线程通过可变参数传入线程函数对象fn，以及函数的参数列表（可以简单理解为通过传值的方式将参数传给该构造函数）


## 拷贝构造函数

```c++
thread(thread&) = delete;
thread(const thread&) = delete;  // 禁用拷贝构造函数
thread(const thread&&) = delete;
```

线程不支持拷贝构造



## 移动构造

```c++
thread(thread&& __t) noexcept
```

转移参数x所代表的可执行指令的所有权，而不会影响线程的执行，转移后，参数x不再代表任何执行线程。



## operator=

```cpp
thread& operator=(const thread&) = delete; // 禁用拷贝赋值运算符
thread& operator=(thread&& __t) noexcept
```

thread对象不允许拷贝构造，同样的对于赋值操作符的重载实质是移动赋值。





# thread可调用对象

创建 thread 对象后会将调用的执行代码（即可调用对象）传递到thread 对象的构造函数中。可调用对象可以是以下五个项中的任何一个：

- 函数指针
- Lambda 表达式
- 函数对象
- 非静态成员函数
- 静态成员函数



定义可调用对象后，我们将其传递给 thread 构造函数。



1.使用函数指针启动线程

```c++
//函数指针可以是可调用对象，传递给 std::thread 构造函数以初始化线程。
void foo(param)
{ 
   ... 
}
// The parameters to the function are put after the comma
std::thread thread_obj(foo, params);
```



2.使用 Lambda 表达式启动线程

```c++
//定义一个lambda表达式
auto f = [](params)
{
	...
};

//使用 lambda 表达式作为可调用对象来启动
std::thread thread_obj(f, params);

```



3.使用函数对象启动线程

```c++
// 定义一个函数对象
class fn_object_class {
	// 重载operator()
	void operator()(params)
	{ 
	   ...
	}
}

std::thread thread_obj(fn_object_class(), params);
```



4.使用非静态成员函数启动线程

```c++
// 定义一个类
class Base {
public:
	// 非静态成员函数
	void foo(param) { ... }
}

//创建Base类对象b
Base b;

// 第一个参数是类非静态成员函数的引用
// 第二个参数类对象的引用
// 第三个参数是非静态成员函数的参数
std::thread thread_obj(&Base::foo, &b, params);

```





5.使用静态成员函数启动线程

```c++
// 定义一个类
class Base {
public:
	//静态成员数
	static void foo(param) { ... }
}

//创建Base类对象b
Base b;
// 其一个参数是类静态成员函数的引用
// 第二个参数是该函数的参数
std::thread thread_obj(&Base::foo, params);
```









# thread接口join

join()函数调用后主线程都要一直等待 thread 对象关联的线程执行完毕，然后再继续执行主线程或其他调用join()的线程。



行为：
同步执行：join()会阻塞调用它的线程，直到关联线程完成执行并结束
资源释放：join()等待关联线程结束后，会释放该线程的系统资源，包括线程栈和控制块等。这样可以防止资源泄露或孤立线程。
状态变化：join()后，std::thread对象的joinable()状态会变为false，防止再次join()



示例

```c++
#include <stdio.h>  // C语言的标准库，包含C语言流操作 printf等
#include <iostream> // 包含输入和输出操作
#include <string.h> // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h> // pause()头文件

#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;

void pause_thread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "暂停 " << n << " 秒结束\n";
}

int main()
{
    printf("--------------------begain-------------------\n");

    cout << "Run Main Thread" << endl;

    std::cout << "生成三个线程...\n";
    std::thread t1(pause_thread, 1); // 线程这时候就已经开始启动
    std::thread t2(pause_thread, 2); // 线程这时候就已经开始启动
    std::thread t3(pause_thread, 3); // 线程这时候就已经开始启动

    std::cout << "线程已经生成，等待加入...:\n";
    t1.join();
    t2.join();
    t3.join();

    // 主线程等待三个线程结束后继续运行
    std::cout << "所有线程加入!\n";

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}
```

结果

```
--------------------begain-------------------
Run Main Thread
生成三个线程...
线程已经生成，等待加入...:

暂停 1 秒结束
暂停 2 秒结束
暂停 3 秒结束
所有线程加入!
--------------------end----------------------
```

std::cout << "所有线程加入!\n"; 词语句被阻塞等待三个线程执行完毕在执行.



# thread接口detach

detach()函数调用后会把主线程和新线程分离开，新线程的事情不影响主线程做事，后台自动回收。



下面的例子创建三个线程并分离，主线程等待三个线程5秒时间。

注意主线程结束会调用exit()，此函数将整个进程结束，所有的线程都会退出。

线程分离后不可接合并且可以安全地销毁。













```
--------------------begain-------------------
Run Main Thread
生成三个线程...
线程已经生成，等待加入...:

暂停 1 秒结束
暂停 2 秒结束
暂停 3 秒结束
所有线程加入!
--------------------end----------------------
```











































# 六、总结

以上就是今天要讲的内容，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
1. https://blog.csdn.net/WangPaiFeiXingYuan/article/details/131022142
1. 







一、https://blog.csdn.net/jianmo1993/article/details/134217076





二、 
三、 



原文链接：https://blog.csdn.net/qaaaaaaz/article/details/130794725





原文链接：https://blog.csdn.net/LeoLei8060/article/details/139476548









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


