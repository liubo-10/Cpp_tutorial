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



# C++\_并发编程_01_mutex



# mutex简介

std::mutex，基本互斥锁，又叫互斥量，是C++标准库中提供的最基本的互斥锁类型之一。它用于实现线程间对共享资源的互斥访问，即在一个时间点只允许一个线程获得锁，其他线程需要等待锁被释放才能继续执行。使用std::mutex可以保证多个线程对共享资源的访问顺序，并避免数据竞争产生的问题。



互斥锁是一种简单的加锁的方法来控制对共享资源的访问，互斥锁只有两种状态,即上锁( lock )和解锁( unlock )，std::mutex 既不可复制亦不可移动。



# mutex使用的场景

在多任务操作系统中，同时运行的多个任务都需要使用同一种资源，为了保护共享资源，在线程里可以采用添加互斥锁的方法。



具体事例：

比如，同一个文件，可能一个线程会对其进行写操作，而另一个线程需要对这个文件进行读操作，可想而知，如果写线程还没有写结束，而此时读线程开始了，或者读线程还没有读结束而写线程开始了，那么最终的结果显然会是混乱的。





# mutex的特点

1. 原子性：把一个互斥量锁定为一个原子操作，这意味着如果一个线程锁定了一个互斥量，没有其他线程在同一时间可以成功锁定这个互斥量；

2. 唯一性：如果一个线程锁定了一个互斥量，在它解除锁定之前，没有其他线程可以锁定这个互斥量；

3. 非繁忙等待：如果一个线程已经锁定了一个互斥量，第二个线程又试图去锁定这个互斥量，则第二个线程将被挂起（不占用任何cpu资源），直到第一个线程解除对这个互斥量的锁定为止，第二个线程则被唤醒并继续执行，同时锁定这个互斥量。

# mutex的使用

头文件：

```c++
#include <<mutex>
```

## mutex操作

互斥锁主要就是用来保护共享资源的，通过调用类成员函数lock()和unlock()来实现加锁和解锁，加锁和解锁，必须成对使用。除此之外，互斥量的使用时机，也要注意，正确的加锁方式应当是在执行读写操作的具体部分加锁。

### lock

锁住互斥量。调用lock时有三种情况:

1.如果互斥量没有被锁住，则调用线程将该mutex锁住，直到调用线程调用unlock释放。
2.如果mutex已被其它线程lock，则调用线程将被阻塞，直到其它线程unlock该mutex。
3.如果当前mutex已经被调用者线程锁住，则std::mutex死锁，而recursive系列则成功返回。

### try_lock

尝试锁住mutex，调用该函数同样也有三种情况:

1.如果互斥量没有被锁住，则调用线程将该mutex锁住(返回true)，直到调用线程调用unlock释放。
2.如果mutex已被其它线程lock，则调用线程将失败，并返回false。
3.如果当前mutex已经被调用者线程锁住，则std::mutex死锁，而recursive系列则成功返回true。



与lock不同的是try_lock，非阻塞，获取不到锁后，会返回非0，适用于获取不到锁后可以进行其他操作的场景。



### unlock

解锁mutex，释放对mutex的所有权。值得一提的时，对于recursive系列mutex，unlock次数需要与lock次数相同才可以完全解锁。
下面给出一个mutex小例子:
















































# 六、总结

以上就是今天要讲的内容，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. https://blog.csdn.net/m0_75215937/article/details/135041309
2. https://blog.csdn.net/weixin_42127358/article/details/123507748
3. https://blog.csdn.net/weixin_39658118/article/details/103619379
4. https://blog.csdn.net/m0_60630094/article/details/119592281

















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

