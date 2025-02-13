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



# 初识智能指针



# 一、什么是智能指针

智能指针不是指针，是一个管理指针的类，用来存储指向动态分配对象的指针，负责自动释放动态分配的对象，防止堆内存泄漏和悬空指针等问题。

动态分配的资源，交给一个类对象去管理，当类对象生命周期结束时，自动调用析构函数释放资源。



# 二、智能指针历史历程

- C++ 98 中产生了第一个智能指针auto_ptr。
- C++boost给出了更加实用的scoped_ptr（防止拷贝） 和 shared_ptr（引进引用计数） 和 weak_ptr。
- C++ 11 引入了unquie_ptr 和 shared_ptr 和 weak_ptr .需要注意的是，unique_ptr对应的是boost中的scoped_ptr。并且这些智能指针的实现是参照boost中的实现的。



# 三、为什么需要智能指针

## 3.1内存泄漏

先来了解一下什么是内存泄漏。

内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。

内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。

> **内存泄漏的危害：**长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致程序响应越来越慢，最终卡死。



## 3.2内存泄漏实例

### 实例1

```c++
void fxx()
{
    int* p1 = new int[10];
    int* p2 = new int[20];
    int* p3 = new int[30];

    //...
 
    delete[] p1;
    delete[] p2;
    delete[] p3;

}
```
如果指针p2或者p3开辟空间new错误，这里就会导致后面的delete不会被执行，这就导致了指针p1的内存泄漏。



可以用异常来解决，但是很难看：

```c++
void fxx()
{
    int* p1 = new int[10];
    int *p2, *p3;
    try {
        p2 = new int[20];
        try {
            p3 = new int[30];
        } catch (...) {
            delete[] p1;
            delete[] p2;
            throw;
        }
    } catch (...) {
        delete[] p1;
        throw;
    }

    //...

    delete[] p1;
    delete[] p2;
    delete[] p3;
}

```

































# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、 https://blog.csdn.net/weixin_75172965/article/details/138239359





















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
