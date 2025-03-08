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

> # Ctitle\_01_介绍

# title

hfghgh

## fdfdf

sdfgsgfg













### 3．1.1.2 分配函数与释放函数

· C：malloc、calloc、realloc / free

· C++：new / delete

#### **1）*****\*1.1.2.1\**** [malloc](https://so.csdn.net/so/search?q=malloc&spm=1001.2101.3001.7020) ***\*/ free\****

大多数实现所分配的存储空间比所要求的要稍大一些，额外的空间用来记录管理信息——分配块的长度，指向下一个分配块的指针等等

· malloc函数向内存申请一块连续可用的空间

· 开辟成功则返回一个指向该空间的***\*void\* 型指针\****，所以需要对其进行***\*强制类型转换\****，转换成我们想要的类型

· 开辟失败则返回 NULL，所以一定要对malloc的***\*返回值进行检查\****

· free 用来***\*释放\****动态开辟的***\*内存\****，而不是释放指针

```
int* ptr = NULL;

ptr = (int*)malloc(1000*sizeof(int));**//开辟一千个int大小的内存，并强制类型转换**

if(NULL == ptr){

	exit(1);

}

free(ptr);

ptr = NULL;
```



· 释放只能一次，如果释放两次及两次以上会出现错误

· 释放空指针例外，释放空指针其实也等于什么都没做，所以释放空指针释放多少次都没有问题

#### **2）*****\*1.1.2.2 new / delete\****

new分配内存步骤

· 调用operator new 函数

· 调用相应的构造函数构造对象，并传入初值

· 对象构造完成后，返回一个指向该对象的指针

delete释放内存步骤

· 调用对象的析构函数

· 调用operator delete 函数释放内存空间

**//开辟变量**

int* a = new int(10);

delete a;

 

**//开辟数组**

int* arr = new int[10];

delete[] arr;

· 1

· 2

· 3

· 4

· 5

· 6

· 7

#### **3）*****\*1.1.2.3 new/delete 与 malloc/free 区别\****

**·** ***\*开辟位置\****

o 严格来说，malloc动态开辟的内存在堆区，new开辟的叫做自用存储区

o 若不重载new操作符，c++编译器一般默认使用堆来实现自用存储，此时等价于堆区

o 特别：new可以不为对象分配内存

**·** ***\*重载\****

o new 、delete 是操作符，可以重载，只能在C++ 中使用。 malloc、free 是函数，可以覆盖，C、C++ 中都可以使用。

**·** ***\*是否调用构造与析构函数\****

o new 可以调用对象的构造函数，对应的delete 调用相应的析构函数。malloc 仅仅分配内存，free 仅仅回收内存，并不执行构造和析构函数

**·** ***\*是否需要指定内存大小\****

o malloc 需要显式指出开辟内存的大小，new 无需指定，编译器会自动计算

**·** ***\*返回值类型\****

o new返回的是某种数据类型指针，malloc返回的是void 指针，new比malloc更安全

o new内存分配失败时，会抛出bac_alloc异常，不会返回NULL；malloc开辟内存失败会返回NULL指针，所以需要判断

#### **4）*****\*1.1.2.5 calloc 、\****[realloc](https://so.csdn.net/so/search?q=realloc&spm=1001.2101.3001.7020)

calloc(number,size):为number个大小为size的元素开辟一块空间，并把每个字节初始化为0
realloc(内存地址，大小)：用于调整申请的空间大小

#### **5）*****\*1.1.2.6 在C++中，使用malloc申请的内存能否通过delete释放？使用new申请的内存能否用free？\****

***\*不能\****，malloc/free主要为了兼容C，new和 delete 完全可以取代malloc/free的。malloc/free 的操作对象都是必须明确大小的。而且不能用在动态类上。new 和 delete会自动进行类型检查和大小 ，malloc/free不能执行构造函数与析构函数 ，所 以动态对象它是不行的。当然从理论上说使用malloc 申请的内存是可以通过delete释放的 。不过一般不这样写的。而且也不能保证每个C++的运行时都能正常












# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。

# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、 https://blog.csdn.net/as480133937/article/details/123740365
二、 https://blog.csdn.net/weibo1230123/article/details/80210097
三、 LwIP应用开发实战指南：基于STM32

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
