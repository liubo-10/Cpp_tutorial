# STL之vector容器

* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📖

## vector模板介绍

vector模板是C++标准库中的一个容器类，被设计为动态数组，即它可以根据需要自动分配内存空间来存储元素。vector模板的本质是一个类模板，它使用了C++语言中的模板技术，使其能够适应不同的数据类型，提供了一种通用的容器类实现。



vector类使用连续的内存来存储元素，它提供了访问和操作元素的方法，还提供其他方法以帮助用户管理容器的大小和分配内存等。在实际编程中，vector模板可以作为一种通用的容器使用，可以方便地存储和管理各种类型的数据。



头文件:

```C++
#include<vector>
```





## vector特点

1. 动态扩容：vector模板可以动态地扩充容器大小，当容器中元素数量增加时，vector会自动分配更多的内存空间来存储元素。这样可以避免手动分配内存空间带来的麻烦和错误。
2. 随机访问：vector中的元素是连续存储的，因此，可以通过下标的方式（使用[]操作符）来访问任何一个元素。这使得vector可以高效地进行随机访问。
3. 内存管理：vector会自动管理内存，当元素被删除或者容器的大小被缩小时，vector会自动回收不再需要的内存。这种管理方式可以避免内存泄漏问题。
4. 插入和删除元素：vector提供了多种插入和删除元素的方法，如push_back()  pop_back()、erase()等。这些方法可以方便地操作容器中的元素。
5. 大小变化：vector中的元素数量可以随时变化，因此可以方便地进行动态管理。同时，vector还提供了一些方法，如size()、capacity()、empty()等，以帮助用户管理容器的大小和内存分配等问题。



## 函数实现









### 构造函数

- vector():创建一个空vector
- vector(int nSize):创建一个vector,元素个数为nSize
- vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
- vector(const vector&):复制构造函数
- vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中





```C++
vector<int> first;//创建一个值类型为int的空vector

vector<int> second(10);//创建一个10个int的vector，且每个元素初值为0

vector<int> third(10,1);//创建一个10个int的vector，且每个元素初值为1

vector<int> forth(third);//将vector third 拷贝给vector forth ，两者元素值完全相同

vector<int> fifth(third.begin(),third.end()-5);
//将third [third.begin(),third.end()-5)区间的元素赋给fifth

//从数组中获得初值
int b[7]={1,2,3,4,5,6,7};
vector<int> a(b,b+7);
```






### 修改函数

####  assign

作用：将新内容赋给vector，替换其当前内容，并相应地修改其大小。

```C++
std::vector<int> first;
std::vector<int> second;
std::vector<int> third;
 
first.assign (7,100);             // 7 ints with a value of 100
 
std::vector<int>::iterator it;
it=first.begin()+1;
 
second.assign (it,first.end()-1); // the 5 central values of first
 
int myints[] = {1776,7,4};
third.assign (myints,myints+3);   // assigning from array.
```


#### push_back 

作用：在vector当前最后一个元素的末尾添加一个新元素。val的内容被复制(或移动)到新元素中。

将容器大小增加了1，当且仅当新vector大小 > 当前vector容量时，会自动重新分配存储空间。

```c++
std::vector<int> myvector(5,1);
myvector.push_back (5);
```





### 容量

#### size

作用：返回vector中元素的个数。

【注意】vector中保存的实际对象的数量，不一定等于它的存储空间大小（容量）。

```C++
std::vector<int> myints;
std::cout  << myints.size() << std::endl;  //0
 
for (int i=0; i<10; i++) 
    myints.push_back(i);
std::cout << myints.size() << std::endl;  //10
 
myints.insert (myints.end(),10,100);
std::cout  << myints.size() << std::endl; //20
 
myints.pop_back();
std::cout <<  myints.size() << std::endl; //19
```


#### capacity

作用：返回当前为vector分配的存储空间大小（容量），以元素个数表示。

【注意】这个容量不一定等于向量的大小。它可以相等或更大，额外的空间允许容纳增长，而不需要在每次插入时重新分配。这个容量并没有假设向量的大小有限制。当此容量耗尽并且需要更多容量时，容器会自动对其进行扩展(重新分配其存储空间)。vector的大小的理论极限由成员max_size给出。可以通过调用vector::reserve成员显式地改变vector的容量。

```C++
std::vector<int> myvector;
 
// set some content in the vector:
for (int i=0; i<100; i++) myvector.push_back(i);

std::cout << "size: " << myvector.size() << "\n";            //100
std::cout << "capacity: " << myvector.capacity() << "\n";    //128
std::cout << "max_size: " << myvector.max_size() << "\n";    //1073741823
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











