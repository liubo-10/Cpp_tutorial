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


> # C++_并发编程\_thread_01\_基本应用



# 一、thread是什么

多线程是一种功能，它允许并发执行程序的两个或多个部分，以最大限度地利用 CPU。这种程序的每个部分都称为线程。多线程支持是在 C++11 中引入的。在 C++11 之前，我们必须使用 POSIX 线程或库。虽然这个库完成了这项工作，但缺乏任何标准语言提供的功能集导致了严重的可移植性问题。C++ 11 取消了所有这些，并给了我们 std::thread。线程类和相关函数在头文件<thread\>中定义。

类thread表示单个执行线程。线程在构建关联的线程对象时立即开始执行。其定义用于观察和管理应用程序中的执行线程的对象。



包含头文件

```cpp
#include <thread>
```

# 二、thread构造函数

std::thread 是 C++ 中表示单个线程的线程类。要启动线程，我们只需要创建一个新的线程对象，并将要调用的执行代码（即可调用对象）传递到对象的构造函数中。



1.默认构造函数

```cpp
thread() noexcept
```



2.初始化构造函数

```cpp
template <class Fn, class... Args>
explicit thread (Fn&& fn, Args&&... args);
```

该函数使用可变参数模板来构造一个线程对象，用来代表一个新的可join的执行线程。这个执行线程通过可变参数传入线程函数对象fn，以及函数的参数列表（可以简单理解为通过传值的方式将参数传给该构造函数）



3.拷贝构造函数

```cpp
thread(thread&) = delete;
thread(const thread&) = delete;  // 禁用拷贝构造函数
thread(const thread&&) = delete;
```

线程不支持拷贝构造



4.移动构造

```cpp
thread(thread&& __t) noexcept
```

转移参数x所代表的可执行指令的所有权，而不会影响线程的执行，转移后，参数x不再代表任何执行线程。



5.operator=

```cpp
thread& operator=(const thread&) = delete; // 禁用拷贝赋值运算符
thread& operator=(thread&& __t) noexcept
```

thread对象不允许拷贝构造，同样的对于赋值操作符的重载实质是移动赋值。





# 三、thread可调用对象

创建 thread 对象后会将调用的执行代码（即可调用对象）传递到thread 对象的构造函数中。可调用对象可以是以下五个项中的任何一个：

- 函数指针
- Lambda 表达式
- 函数对象
- 非静态成员函数
- 静态成员函数



定义可调用对象后，我们将其传递给 thread 构造函数。



1.使用函数指针启动线程

```cpp
//函数指针可以是可调用对象，传递给 std::thread 构造函数以初始化线程。
void foo(param)
{ 
   ... 
}
// The parameters to the function are put after the comma
std::thread thread_obj(foo, params);
```



2.使用 Lambda 表达式启动线程

```cpp
//定义一个lambda表达式
auto f = [](params)
{
	...
};

//使用 lambda 表达式作为可调用对象来启动
std::thread thread_obj(f, params);

```



3.使用函数对象启动线程

```cpp
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

```cpp
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

```cpp
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



# 四、join()

join()函数调用后主线程都要一直等待 thread 对象关联的线程执行完毕，然后再继续执行主线程或其他调用join()的线程。



行为：
同步执行：join()会阻塞调用它的线程，直到关联线程完成执行并结束
资源释放：join()等待关联线程结束后，会释放该线程的系统资源，包括线程栈和控制块等。这样可以防止资源泄露或孤立线程。
状态变化：join()后，std::thread对象的joinable()状态会变为false，防止再次join()



示例

```cpp
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

std::cout << "所有线程加入!\n"; 此词语句被阻塞等待三个线程执行完毕在执行.



# 五、detach()

detach()函数调用后会把主线程和新线程分离开，新线程的事情不影响主线程做事，后台自动回收。



行为：
分离状态：调用detach()后，std::thread对象与实际线程解绑，线程变为“分离状态”（detached state）。
资源管理：在分离状态下，线程在完成后会自行释放资源，不需要显示调用join()或其他操作。



下面的例子创建三个线程并分离，主线程等待三个线程5秒时间。

注意主线程结束会调用exit()，此函数将整个进程结束，所有的线程都会退出。

线程分离后不可接合并且可以安全地销毁。



示例

```cpp

int main()
{
    printf("--------------------begain-------------------\n");

    cout << "Run Main Thread" << endl;

    std::cout << "生成三个线程...\n";
    std::thread t1(pause_thread, 1); // 线程这时候就已经开始启动
    std::thread t2(pause_thread, 2); // 线程这时候就已经开始启动
    std::thread t3(pause_thread, 3); // 线程这时候就已经开始启动

    std::cout << "线程已经生成，等待分离...:\n";
    t1.detach();
    t2.detach();
    t3.detach();

    std::cout << "所有线程分离!\n";

    // 给被分离线程5秒时间完成，但线程不一定完成!
    pause_thread(5); // 暂停5秒

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
线程已经生成，等待分离...:
所有线程分离!

暂停 1 秒结束
暂停 2 秒结束
暂停 3 秒结束
暂停 5 秒结束
--------------------end----------------------
```

std::cout << "所有线程分离!\n"; 词语句不会被阻塞,直接执行.

不同的系统有不同的现象：

- windows:如果主线程退出了，那么系统会自动回收该进程的所有资源，包括分离出去的线程对象。
- Linux:如果主线程退出了，被分离出去的线程对象会继续运行，结束时自动销毁线程资源。



# 六、joinable()

joinable()函数的作用是确认当前线程是否可以join()，如果joinable()函数的返回值为true，则该线程尚未通过join()终止或通过detach()分离。这意味着可以调用join()。这可以防止多次调用join()函数的错误。



示例

```cpp
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
    std::thread t2(pause_thread, 3); // 线程这时候就已经开始启动

    cout << "joinable t1:" << t1.joinable() << endl;
    cout << "joinable t2:" << t2.joinable() << endl;

    cout << "t1.join:\n";
    t1.join();

    cout << "t2.detach:\n";
    t2.detach();

    cout << "joinable t1:" << t1.joinable() << endl;
    cout << "joinable t2:" << t2.joinable() << endl;

    pause_thread(5); // 暂停5秒

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
joinable t1:1
joinable t2:1
t1.join:      // 阻塞一秒
暂停 1 秒结束
t2.detach:
joinable t1:0
joinable t2:0
暂停 3 秒结束
暂停 5 秒结束
--------------------end----------------------
```







死锁与活锁的区别，死锁与饥饿的区别？
死锁和活锁都是多线程并发编程中的常见问题，它们都会导致线程无法继续执行，但二者的原因和表现略有不同。
死锁是指两个或多个线程在等待对方释放资源的状态下陷入了无限等待的情况。简单来说，就是多个线程互相持有对方所需的资源，导致互相等待无法继续执行。死锁通常是在并发环境下，通过不当的锁使用导致的，需要谨慎避免。
而活锁是指线程一直在运行，但却没有取得进展，看上去像是一直在忙碌，但实际上没有做任何有意义的工作。活锁通常是由于线程间相互协调不当导致的，例如两个线程都主动放弃锁，希望让对方先执行，结果导致两个线程一直在轮流放弃锁，最终无法正常执行。
死锁和饥饿的区别在于，死锁是多个线程互相等待对方所需的资源而导致无限等待，而饥饿是指某个线程无法获取所需的资源而无法继续执行。死锁是由于资源的相互依赖导致的，而饥饿则是因为资源分配不均导致的，一个线程始终无法获取所需的资源而一直无法执行。解决死锁和饥饿问题的方法也不同，需要根据具体情况采取不同的措施。












# 七、总结

以上就是今天要讲的内容，后续会有更多内容。



# 八、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
1. https://blog.csdn.net/WangPaiFeiXingYuan/article/details/131022142
2. https://blog.csdn.net/WangPaiFeiXingYuan/article/details/131022299
3. https://blog.csdn.net/jianmo1993/article/details/134217076
4. https://blog.csdn.net/qaaaaaaz/article/details/130794725
5. https://blog.csdn.net/LeoLei8060/article/details/139476548
6. https://blog.csdn.net/weixin_50503886/article/details/129467956









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

