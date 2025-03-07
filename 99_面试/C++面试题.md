





# C++面试题汇总

## **1.** C基础







































### 17．1.4.8 指针和句柄

· 句柄和指针其实是两个截然不同的概念，window系统用句柄标记系统资源，隐藏系统的信息，它一个一个32bit的整数

· 而指针则标记某个物理内存地址，两者概念不同

### 18．1.4.9 如何避免“野指针”

· 指针变量声明时没有被初始化。解决办法：指针声明时初始化，可以是具体的地址值，也可让它指向NULL。

· 指针p被free或者delete之后，没有置为NULL。解决办法：指针指向的内存空间被释放后指针应该指向NULL。

· 指针操作超越了变量的作用范围。解决办法：在变量的作用域结束前释放掉变量的地址空间并且让指针指向NULL。

### 19．1.4.10 空指针与迷途指针区别

· 当delete一个指针的时候，实际上仅仅是让编译器释放内存，但指针本身依然存在，此时他就是一个迷途指针

· 可令ptr = 0; 使迷途指针变为空指针

## **5.** ***\*1.5 const\****

· 任何不会修改数据成员的函数都应该声明为const 类型

· 在参数中使用const应该使用引用或指针，而不是一般的对象实例

· 除了重载操作符外一般不要将返回值类型定为对某个对象的const引用

### 20．1.5.1 const 使用

**·** ***\*const使用：定义常量、修饰函数参数、修饰函数返回值\****

· const 修饰类的成员变量，表示成员变量，不能被修改

· 如果const构成函数重载，const对象只能调用const函数，非const对象优先调用非const函数

· const 函数只能调用const函数，非const函数可以调用const函数

· 类体外定义的const成员函数，在定义和声明处都需要const修饰符

### 21．1.5.2 const 作用

| ***\*作用\****                     | ***\*说明\****                                               |
| ---------------------------------- | ------------------------------------------------------------ |
| 可以定义const常量                  |                                                              |
| 便于进行类型检查                   | const常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安全检查，而对后者只进行字符替换，没有类型安全检查，并且在字符替换时可能会产生意料不到的错误 |
| 可以保护被修饰的东西               | 防止意外的修改，增强程序的健壮性。                           |
| 可以很方便地进行参数的调整和修改   | 同宏定义一样，可以做到不变则已，一变都变                     |
| 为函数重载提供了一个参考           | void f(int i) {…} //一个函数 void f(int i) const {…} //上一个函数的重载 |
| 可以节省空间，避免不必要的内存分配 | const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是象#define一样给出的是立即数，所以，const定义的常量在程序运行过程中只有一份拷贝，而#define定义的常量在内存中有若干个拷贝 |
| 提高了效率                         | 编译器通常不为普通const常量分配存储空间，而是将它们保存在符号表中，这使得它成为一个编译期间的常量，没有了存储与读内存的操作，使得它的效率也很高 |

参考链接：https://blog.csdn.net/moli152_/article/details/45100717

### 22．1.5.3 如何修改const成员函数

用mutable修饰成员变量名后，就可以修改类成员变量

### 23．1.5.4 将Const类型转化为非Const类型

采用const_cast 进行转换。
用法：const_cast <type_id> (expression)

## **6.** ***\*1.6 sizeof\****

数据对齐原则：是指数据所在的内存地址必须是该数据长度的整数倍。

### 24．1.6.1 sizeof 和strlen 的区别

· sizeof是一个操作符，strlen是库函数。

· sizeof的参数可以是数据的类型，也可以是变量、函数；而strlen只能用char*做参数且且以结尾为‘\0’的字符串。

· 编译器在编译时就计算出了sizeof的结果，而strlen函数必须在运行时才能计算出来。并且sizeof计算的是数据类型占内存的大小，而strlen计算的是字符串实际的长度。

· 数组做sizeof的参数不退化，传递给strlen就退化为指针了

· sizeof不能返回被动态分配的数组或外部的数组的尺寸

· sizeof不能作用于函数类型，不完全类型或位字段，不完全类型是指具有未知存储大小数据的类型，如未知存储大小的数组类型、未知内容的结构或联合类型、void类型等

### 25．1.6.2 sizeof 的使用场合

· 其中一个主要用途就是与存储分配和I/O系统那样的例程通信

· 可以查看某种类型的对象在内存中所占的单元字节

· 在动态分配一个对象时，可以让系统知道要分配多少内存

· 便于一些类型的扩充。在window中有很多结构类型就有一个专用的字段来存放该类型的字节大小

· 如果操作数是函数中的数组形参或函数类型的形参，sizeof给出其指针的大小

## **7.** ***\*1.7 强制类型转换运算符\****

***\*static_cast\****

· 用于非多态类型的转换

· 不执行运行时类型检查（转换安全性不如 dynamic_cast）

· 通常用于转换数值数据类型（如 float -> int）

· 可以在整个类层次结构中移动指针，子类转化为父类安全（向上转换），父类转化为子类不安全（因为子类可能有不在父类的字段或方法）

· 用于各种隐式转换，比如非const转const，void*转指针等, static_cast能用于多态向上转化，如果向下转能成功但是不安全，结果未知

***\*dynamic_cast\****

· 用于多态类型的转换，只能用于含有虚函数的类

· 执行行运行时类型检查

· 只适用于指针或引用

· 对不明确的指针的转换将失败（返回 nullptr），但不引发异常

· 可以在整个类层次结构中移动指针，包括向上转换、向下转换

***\*const_cast\****

· 用于将const变量转为非const

· 用于删除 const、volatile 和 __unaligned 特性（如将 const int 类型转换为 int 类型 ） reinterpret_cast

· 用于位的简单重新解释

· 滥用 reinterpret_cast 运算符可能很容易带来风险。除非所需转换本身是低级别的，否则应- 使用其他强制转换运算符之一。

· 允许将任何指针转换为任何其他指针类型（如 char* 到 int* 或 One_class* 到 Unrelated_class* 之类的转换，但其本身并不安全）

· 也允许将任何整数类型转换为任何指针类型以及反向转换。

· reinterpret_cast 运算符不能丢掉 const、volatile 或 __unaligned 特性。

· reinterpret_cast 的一个实际用途是在哈希函数中，即，通过让两个不同的值几乎不以相同的索引结尾的方式将值映射到索引。

***\*bad_cast\****

· 由于强制转换为引用类型失败，dynamic_cast 运算符引发 bad_cast 异常

try {

​	Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);

}

catch (bad_cast b) {

​	cout << "Caught: " << b.what();

}

· 1

· 2

· 3

· 4

· 5

· 6

***\*为什么不使用C的强制转换？\****
C的强制转换表面上看起来功能强大什么都能转，但是转化不够明确，不能进行错误检查，容易出错。

## **8.** ***\*1.8 什么是右值引用，跟左值又有什么区别？\****

左值和右值的概 念 ：

· 左值：能取地址，或者具名对象，表达式结束后依然存在的持久对象；

· 右值：不能取地址，匿名对象，表达式结束后就不再存在的临时对象； 区别：

· 左值能寻址，右值不能；

· 左值能赋值，右值不能；

· 左值可变，右值不能（仅对基础类型适用，用户自定义类型右值引用可以通过成员函数改变）

### 26．1.9 变量的声明和定义有什么区别

变量的定义为变量分配地址和存储空间，变量的声明不分配地址。一个变量可以在多个地方声明，但是只在一个地方定义。 加入extern 修饰的是变量的声明，说明此变量将在文件以外或在文件后面部分定义

### 27．1.10 说一说extern“C”

extern“C”的主要作用就是为了能够正确实现C++代 码调用其他C语言代码 。加 上
extern“C” 后，会指示编译器这部分代码按C语言（而不是C++）的 方式进行编译。由于C++ 支持函数重载，因此编译器编译函数的过程中会将函数的参数类型也加到编译后的代码中，而不仅仅是函数名；而C语言并不支持函数重载，因此编译C语言代码的函数时不会带上函数的参数类型， 一般只包括函数名。

# 2. C++面向对象

对象是类的实例，类不分配存储空间，对象才分配存储空间，空类对象大小为1字节

## **9.** ***\*2.1 面对对象的三大特性（基本特征）\****

· 封装性：将客观事物抽象成类，每个类对自身的数据和方法实行 protection （private ， protected ，public ）。

· 继承性：广义的继承有三种实现形式：

o 实现继承（使用基类的属性和方法而无需额外编码的能力)

o 可视继承(子窗体使用父窗体的外观和实现代码)

o 接口继承(仅使用属性和方法,实现滞后到子类实现)。

· 多态性：是将父类对象设置成为和一个或更多它的子对象相等的技术。用子类对象给父类对象赋值之后，父类对象就可以根据当前赋值给它的子对象的特性以不同的方式运作。

## **10.** ***\*2.2 封装\****

· 意义

o 将属性和行为作为一个整体表现事物

o 对属性和行为加以权限控制（公共、保护、私有）

o 增加代码的内聚性，进而提高可复用性和可维护性

· 封装手法

o 通过文件：对头文件的包含，把相关定义，声明等封装到某个头文件中

o 通过语法：C++的namespace、Java的package、Python的module等

## **11.** ***\*2.3 继承\****

· 分类

o 继承（泛化）

§ 可视继承

§ 实现继承

o 组合（聚合）

§ 接口继承

§ 纯虚数

## **12.** ***\*2.4 多态\****

· 静态多态（编译阶段，地址早绑定）

o 函数重载：包括普通函数的重载和成员函数的重载

o 函数模板的使用：通过将类型作为参数，传递给模板，可使编译器生成该类型的函数。

· 动态多态（运行阶段，地址晚绑定）在程序执行期间(非编译期)判断所引用对象的实际类型，根据其实际类型调用相应的方法。

o 派生类

o 虚函数

## **13.** ***\*2.5 成员函数\****

### 28．2.5.1 构造函数与析构函数

· 构造函数（constructor）：主要作用在于创建对象时为对象的成员属性赋值，由编译器自动调用，可以有参数，可以重载

· 析构函数（destructor）：主要在于对象销毁前系统自动调用。执行一些清理工作，无参数，且不能重载

### 29．2.5.2 初始化列表方式

构造函数( ) : 属性1(值1)，属性1(值1)，...{ }

· 1

***\*常量必须在构造函数的初始化列表里初始化，或者将其设置为static\****

### 30．2.5.3 构造函数调用方式

· 括号法：Person p1(10); //无参构造不加括号；Person p1;

· 显式法：Person p2 = Person(10);Person p2 = Person(p1);

· 隐式转换法：Person p3 = 10;

o Person(10)单独写为匿名对象，当前行结束后立刻析构

### 31．2.5.4 C++的空类默认产生哪些成员函数

· 缺省构造函数

· 缺省拷贝构造函数。

· 缺省析构函数。

· 缺省赋值运算符。

· 缺省取址运算符。

· 缺省取址运算符 const 。

两个函数也是空类的默认函数，只有当实际使用这些函数的时候，编译器才会去定义它们。

### 32．2.5.5 继承中子类和父类的构造和析构顺序

· 构造：先调用父类的构造函数，然后再调用子类构造函数

· 析构：先调用子类析构函数，然后再调用父类的析构函数

### 33．2.5.6 深拷贝与浅拷贝

浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间进行拷贝操作

### 34．2.5.6 拷贝构造函数与赋值运算符

***\*拷贝构造函数和赋值运算符重载有以下两个不同之处：\****

· 拷贝构造函数生成新的类对象，而赋值运算符不能。

· 由于拷贝构造函数是直接构造一个新的类对象，所以在初始化这个对象之前不用检验源对象 是否和新建对象相同。而赋值运算符则需要这个操作，另外赋值运算中如果原来的对象中有内存分配要先把内存释放掉。

***\*注意\****：当有类中有指针类型的成员变量时 ，一 定要重写拷贝构造函数和赋值运算符，不要使用默认的 。

***\*拷贝构造函数调用时机：\****

· 使用一个已经创建完毕的对象来初始化一个新对象

· 值传递的方式给函数参数传值

· 以值方式返回局部对象

### 35．2.5.7 C 语言的关键字 static 和 C++ 的关键字 static 有什么区别

· 在 C 中static 用来修饰局部静态变量和外部静态变量、函数而C++中除了上述功能外， 还用来定义类的成员变量和函数。 即静态成员和静态成员函数 。

· 注意：编程时static 的记忆性和全局性的特点可以让在不同时期调用的函数进行通信，传递信息 ，而C++ 的静态成员则可以在多个对象实例间进行通信，传递信息

### 36．2.5.8 静态成员

· 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员

· 静态成员变量：所有对象共享同一份数据；在编译阶段分配内存，类内声明，类外初始化

· 静态成员函数：所有对象共享同一个函数；静态成员函数只能访问静态成员变量

· 非静态成员变量占用对象空间，静态成员变量、函数不占用对象空间

### 37．2.5.9 常函数与常对象

· 常函数

o 成员函数后加const 后，称这个函数为常函数

o 常函数内不可以修改成员属性

o 成员属性声明前加关键字mutable 后，在常函数中依然可用修改

· 常对象

o 声明对象前加const 称该对象为常对象

o 常对象只能调用常函数

## **14.** ***\*2.6 引用\****

### 38．2.6.1 引用

引用是某个目标变量的别名：类型标识符 &引用名 = 目标变量；int &a = b;

### 39．2.6.2 常引用

· const 类型标识符 &引用名 = 目标变量；const int &a = b;

· 可以提高程序的效率，保护传递给函数的数据不在函数中改变

### 40．2.6.3 引用与指针区别

见 1.4.6

## **15.** ***\*2.7 虚函数\****

### 41．2.7.1 虚函数与纯虚函数

· 虚函数：

o virtual 返回值类型 函数名（参数列表）{ }

o 在基类中冠以virtual的成员函数，它提供了一个接口界面。允许在派生类中对基类的虚函数重新定义

o 使用虚函数有一定的空间开销，当类中有虚函数时，编译器会为该类构造一个虚函数表

o 虚函数表是一个指针数组用来存放每个虚函数的入口地址

· 纯虚函数

o virtual 返回值类型 函数名（参数列表）= 0；

o 在基类中为其派生类保留一个函数的名字，以便派生类根据需要对他进行定义

o 作为接口存在，纯虚函数不具备函数的功能，一般不能直接被调用。

o 从基类继承来的纯虚函数，在派生类仍然是虚函数。

### 42．2.7.2 抽象类

· 如果一个类中至少有一个纯虚函数，那么这个类被称为抽象类（abstract class）

· 抽象类中不仅包括纯虚函数，也可包括虚函数。

· 抽象类必须用作派生其他类的基类。且不能直接创建对象实例。但仍可使用指向抽象类的指针支持运行时多态性。

· 特点

o 无法实例化对象

o 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

### 43．2.7.3 虚析构与纯虚析构

· 多态使用时，若子类有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码，此时将父类中的析构函数改为虚析构或者纯虚析构即可

· 总结

o 解决通过父类指针释放子类对象

o 子类中没有堆区数据，可不写为虚析构或纯虚析构

o 拥有纯虚析构的类也称为抽象类

### 44．2.7.4 多态类中的虚函数表是compile-Time建立的还是Run-Time建立的

虚拟函数表是在编译时期就建立了，各个虚函数这时候已经被组织成一个虚拟函数的入口地址的数组。而对象的隐藏成员----虚函数表指针是在运行期间，也就是构造函数被调用时进行初始化的，这是实现多态的关键

### 45．2.7.5 析构函数可为virtual型，构造函数不能，为什么？

虚函数采用一种虚调用的方法，虚调用是一种可以在只有部分信息的情况下工作的机制，特别允许我们调用一个只知道接口而不知道其准确对象类型的函数，但是如果要创建一个对象，势必要知道对象的准确类型，因此构造函数不能为虚

### 46．2.7.6 能否把每个函数都声明为虚函数？

不能，虚函数是有代价的：由于每个虚函数的对象都必须维护一个v表，因此在使用虚函数的时候都会产生一个系统开销。如果仅是一个很小的类，且不想派生其他类，那么根本没必要使用虚函数

## **16.** ***\*2.8 隐藏、重载与重写\****

![img](file:///C:\Users\ADMINI~1\AppData\Local\Temp\ksohtml16288\wps2.jpg) 

· 重写/覆盖（override）：函数返回值类型，函数名，参数列表完全一致称为重写

· 重载(overload)：同一作用域下函数名相同，参数类型、个数、顺序不同

o 函数的返回值不可以做重载的条件
（1）重写和重载主要有以下几点不同。

· 范围的区别：被重写的和重写的函数在两个类中，而重载和被重载的函数在同一个类中。

· 参数的区别：被重写函数和重写函数的参数列表一定相同，而被重载函数和重载函数的参数列表一 定不同。

· virtual 的区别：重写的基类中被重写的函数必须要有virtual 修饰，而重载函数和被重载函数可以被 virtual
修饰，也可以没有。

（2）隐藏和重写、重载有以下几点不同 。

· 与重载的范围不同：和重写一样，隐藏函数和被隐藏函数不在同一个类中。

· 参数的区别：隐藏函数和被隐藏的函数的参数列表可以相同，也可不同，但是函数名肯定要相同。 当参数不相同时，无论基类中的参数是否被virtual 修饰，基类的函数都是被隐藏，而不是被重写。

注意：虽然重载和覆盖都是实现多态的基础，但是两者实现的技术完全不相同 ，达到的目的也是完全不同的，覆盖是动态态绑定的多态 ，而重载是静态绑定的多态 。
图片参考链接：https://blog.csdn.net/qq_37934101/article/details/81365449

## **17.** ***\*2.9 class 与struct 区别\****

· 默认继承权限不同，class默认继承权限是private，struct默认继承权限是public

· class 还可用于定义模板参数 ，像typename，但是关键字struct不能用于定义模板参数.

## **18.** ***\*2.10 友元\****

· 友元是定义在类外部的普通函数

· 需要在类体内进行说明，需加上关键字friend

· 友元不是成员函数，但是它可以访问类中的私有成员

· 作用在于提高程序运行效率，但是破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员

· 友元可以是一个函数（全局函数、成员函数），被称为友元函数；可用是一个类，被称为友元类



# 4. C++ 11

## **39.** ***\*4.1 NULL与nullptr\****

### 47．4.1.1 C语言中的NULL

· C语言中的NULL通常被定义为：#define NULL ((void *)0)

· NULL实际上是一个空指针，C语言中把空指针赋给int和char指针的时候，发生了隐式类型转换，把void指针转换成了相应类型的指针。

### 48．4.1.2 C++中的NULL

C++是强类型语言，void*是不能隐式转换成其他类型的指针的，所以实际上编译器提供的头文件做了相应的处理：

\#ifdef __cplusplus

\#define NULL 0

\#else

\#define NULL ((void *)0)

\#endif

· 1

· 2

· 3

· 4

· 5

实际上，用NULL代替0表示空指针在函数重载时会出现问题；

void func(void* i);**//func(nullptr)**

void func(int i);**//func(NULL)**

· 1

· 2

### 49．4.1.3 C++中的nullptr

· nullptr可以明确区分整型和指针类型，能够根据环境自动转换成相应的指针类型，但不会被转换为任何整型，所以不会造成参数传递错误。

· nullptr的l另一种实现方式如下：

\#include <iostream>

using namespace std;

 

void func(void* i)

{

​	cout << "func1" << endl;

}

 

void func(int i)

{

​	cout << "func2" << endl;

}

 

void main(int argc,char* argv[])

{

​	func(NULL);

​	func(nullptr);

​	getchar();

}





---

---
