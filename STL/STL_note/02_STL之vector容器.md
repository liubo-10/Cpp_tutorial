* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📖



# vector容器

vector模板是C++标准库中的一个容器类，被设计为动态数组，即它可以根据需要自动分配内存空间来存储元素。vector模板的本质是一个类模板，它使用了C++语言中的模板技术，使其能够适应不同的数据类型，提供了一种通用的容器类实现方法。vector类使用连续的内存来存储元素，它提供了访问和操作元素的方法，还提供其他方法以帮助用户管理容器的大小和分配内存等,可以方便地存储和管理各种类型的数据。



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





所谓动态增加大小，并不是在原空间之后续接新空间(因为无法保证原空间之后尚有可配置的空间)，而是一块更大的内存空间，然后将原数据拷贝新空间，并释放原空间。因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了。这是程序员容易犯的一个错误，务必小心。


Vector的实现技术，关键在于其对大小的控制以及重新配置时的数据移动效率，一旦vector旧空间满了，如果客户每新增一个元素，vector内部只是扩充一个元素的空间，实为不智，因为所谓的扩充空间(不论多大)，一如刚所说，是”配置新空间-数据移动-释放旧空间”的大工程,时间成本很高，应该加入某种未雨绸缪的考虑，稍后我们便可以看到vector的空间配置策略。





### vector与array

vector的数据安排以及操作方式，与array（数组）非常相似，两者的唯一差别在于空间的运用的灵活性。

Array是静态空间，一旦配置了就不能改变，要换大一点或者小一点的空间，可以，一切琐碎得由自己来，首先配置一块新的空间，然后将旧空间的数据搬往新空间，再释放原来的空间。

Vector是动态空间，随着元素的加入，它的内部机制会自动扩充空间以容纳新元素。因此vector的运用对于内存的合理利用与运用的灵活性有很大的帮助，我们再也不必害怕空间不足而一开始就要求一个大块头的array了。











## 3.1 vector的底层原理

· vector底层是一个动态数组 ，包含三个迭代器， start和finish之间是已经被使用的空间范围 end _ of _ storage是整块连续空间包括备用空间的尾部 。

· 当空间不够装下数据（ vec . push_ back( val) ）时，会自动申请另一片更大的空 间（1.5倍或者2倍） ，然后把原来的数据拷贝到新的内存空间，接着释放原来的 那片空间[vector内存增长机制] 。

· 当释放或者删除（ v ec . c l e ar ()）里面的数据时，其存储空间不释放，仅仅是清 空了里面的数据。因此，对vector的任何操作一旦引起了空间的重新配置，指向原vector 的所有迭代器会都失效了 。

## 3.2 vector中的reserve和resize的区别

· reserve是直接扩充到已经确定的大小，可以减少多次开辟、释放空间的问题（优化push_back），就可以提高效率，其次还可以减少多次要拷贝数据的问题。reserve只是保证vector中的空间大小（capacity）最少达到参数所指定的大小n。reserve()只有一个参数。

· resize()可以改变有效空间的大小，也有改变默认值的功能。capacity的大小也会随着改变。resize()可以有多个参数。

## 3.3 vector中的size和capacity的区别

· size表示当前vector中有多少个元素（finish - start）;

· capacity函数则表示它已经分配的内存中可以容纳多少元素（end_of_storage - start）;

## 3.4 vector中erase方法与algorithn中的remove方法区别

· vector中erase方法真正删除了元素，迭代器不能访问了

· remove只是简单地将元素移到了容器的最后面，迭代器还是可以访问到。因为algorithm通过迭代器进行操作，不知道容器的内部结构，所以无法进行真正的删除。

## 3.5 vector迭代器失效的情况

· 当插入一个元素到vector中，由于引起了内存重新分配，所以指向原内存的迭代器全部失效。

· 当删除容器中一个元素后,该迭代器所指向的元素已经被删除，那么也造成迭代器失效。erase方法会返回下一个有效的迭代器，所以当我们要删除某个元素时，需要it=vec.erase(it);。

## 3.6 正确释放vector的内存(clear(), swap(), shrink_to_fit())

· vec.clear()：清空内容，但是不释放内存。

· vector().swap(vec)：清空内容，且释放内存，想得到一个全新的vector。

· vec.shrink_to_fit()：请求容器降低其capacity和size匹配。

· vec.clear();vec.shrink_to_fit();：清空内容，且释放内存。

































## 函数

### 构造函数

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



### vector赋值操作

```c++
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
```

### vector大小操作

```c++
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问
```

### vector数据存取操作

```c++
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
```

### vector插入和删除操作

```c++
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
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











