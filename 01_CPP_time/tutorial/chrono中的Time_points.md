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

# chrono中的Time_points
在时钟类中，时间点由类模板std::chrono::time_point<>的实例表示，



时间点是一个时间跨度，始于一个称为时钟纪元的特定时刻，终于该时间点本身。跨度的值表示某具体时长的倍数。









时钟纪元是一个基础特性，却无法直接查询，C++标准也未进行定义。典型的时钟纪元包括1970年1月1日0时0分0秒，或运行应用的计算机的启动时刻。多个时钟可能共享一个时钟纪元，也可能分别有各自的时钟纪元。时钟类内部具有一个time_point类型的typedef，假设两个时钟类都参考同一个纪元，则可用该typedef指定跟另一个时钟类里面的time_point[20]。时钟类内部具有一个time_point成员类型的typedef。假设两个时钟类都参考同一个时钟纪元，则可用该typedef指定跟另一个时钟类共用的time_point成员类型。尽管时钟纪元的时刻无从得知，不过，我们可以在给定的时间点上调用time_since_epoch()，这个成员函数返回一个时长对象，表示从时钟纪元到该时间点的时间长度。













chrono库中提供了一个表示时间点的类 time_point











类模板的定义如下：

```c++
template <typename _Clock, typename _Dur>
struct time_point
```

它的第一个模板参数指明所参考的时钟，第二个模板参数指明计时单元（std::chrono::duration<>的特化）。



它被实现成如同存储一个 Duration 类型的自 Clock 的纪元起始开始的时间间隔的值，通过这个类最终可以得到时间中的某一个时间点。

- Clock：此时间点在此时钟上计量
- Duration：用于计量从纪元起时间的 std::chrono::duration 类型







在这个类中除了构造函数还提供了另外一个time_since_epoch()函数，用来获得1970年1月1日到time_point对象中记录的时间经过的时间间隔（duration），函数原型如下：







除此之外，时间点time_point对象和时间段对象duration之间还支持直接进行算术运算（即加减运算），时间点对象之间可以进行逻辑运算









time_point类的构造函数原型如下



```c++
// 1. 构造一个以新纪元(epoch，即：1970.1.1)作为值的对象，需要和时钟类一起使用，不能单独使用该无参构造函数
time_point();
// 2. 构造一个对象，表示一个时间点，其中d的持续时间从epoch开始，需要和时钟类一起使用，不能单独使用该构造函数
explicit time_point( const duration& d );
// 3. 拷贝构造函数，构造与t相同时间点的对象，使用的时候需要指定模板参数
template< class Duration2 >
time_point( const time_point<Clock,Duration2>& t );

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
