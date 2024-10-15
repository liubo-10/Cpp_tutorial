# C++ type

* 👋 Hi, I’m bliu2-10
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



熟知基本数据类型是我们正确表达实际问题中各种数据的前提，因此我分类总结了一下基本数据类型，以便日后查阅。

ANSI C/C++基本数据类型：



| Type                                        | Size   | 数值范围               |
| ------------------------------------------- | ------ | ---------------------- |
| 无值型void                                  | 0 byte | 无值域                 |
| 布尔型bool                                  | 1 byte | true  false            |
| 有符号短整型short [int] /signed short [int] | 2 byte | -32768~32767           |
| 无符号短整型unsigned short [int]            | 2 byte | 0~65535                |
| 有符号整型int /signed [int]                 | 4 byte | -2147483648~2147483647 |
| 无符号整型unsigned [int]                    | 4 byte | 0~4294967295           |
| 有符号长整型long [int]/signed long [int]    | 4 byte | -2147483648~2147483647 |
| 无符号长整型unsigned long [int]             | 4 byte | 0~4294967295           |
| long long                                   | 8 byte | 0~18446744073709552000 |
| 有符号字符型char/signed char                | 1 byte | -128~127               |
| 无符号字符型unsigned char                   | 1 byte | 0~255                  |
| 宽字符型wchar_t (unsigned short.)           | 2 byte | 0~65535                |
| 单精度浮点型float                           | 4 byte | -3.4E-38~3.4E+38       |
| 双精度浮点型double                          | 8 byte | 1.7E-308~1.7E+308      |
| long double                                 | 8 byte | 1.7E-308~1.7E+308      |
|                                             |        |                        |
|                                             |        |                        |
|                                             |        |                        |
|                                             |        |                        |
|                                             |        |                        |
|                                             |        |                        |





说明：

（1）类型修饰符signed和unsigned用于修饰字符型和整形。

（2）类型修饰符short和long用于修饰字符型和整形。

（3）当用signed和unsigned、short和long修饰int整形时，int可省略。

（4）其中bool和wchar_t是C++特有的。对于条件判断，零为假，非零为真，对bool变量可赋非0非1的其他真值。

（5）float的精度（6位有效数字）通常是不够的，double类型可以保证10位有效数字，能够满足大多数计算的需要。使用double类型基本不会出错，在float类型中存在隐式的精度损失。默认的浮点字面值常量为double类型，在数值后面加上F或f表示单精度，例如3.14159F。浮点数float、double的存储设计，从本质上来说是设计了一个数值映射，充分利用了二进制存储的特点。参考IEEE754浮点数表示标准。

（6）除上表以外，C/C++都可以自定义枚举enum、联合union和struct结构体类型。

（7）以上sizeof通过Windows XP 32位平台测试，其中某些类型数据的字节数和数值范围由操作系统和编译平台决定。比如16位机上，sizeof(int) = 2，而32位机上sizeof(int) = 4；32位机上sizeof(long) = 4，而64位机上sizeof(long) = 8。除此之外，注意64位机上的pointer占8byte。

（8）void的字面意思是“无类型”，不能用来定义变量。void真正发挥的作用在于：<1> 对函数返回和函数参数的限定，例如自定义既不带参数也无返回值的函数void MyFunc(void);<2>定义无类型通用指针void *，指向任何类型的数据。

（9）标准C++库及STL还提供了通用数据结构：字符串类string；向量类模板vector；双端队列类模板deque；链表类模板list；容器适配器堆栈类stack（实现先进后出的操作）；容器适配器队列类queue（实现先进先出的操作）；集合类set；多重集合类multiset；映射类map；多重映射类multimap；位集合bitset；迭代器iterator (类似指针的功能,对容器的内容进行访问)。

（10）在标准c++中，int的定义长度要依靠你的机器的字长，也就是说，如果你的机器是32位的，int的长度为32位，如果你的机器是64位的，那么int的标准长度就是64位，而vc中__int64是为在32机位机器长实现64位长度的整形数。

（11）关于32位平台下的int和long

long从字面上看，应该是64位才更合理，把long当成32位实在是一个历史的包袱。像C#那样新起炉灶的程序语言，由于没有需要支持老代码的问题，就把long当作64位来处理了。



在32位平台下，long是相对short而言，long（short）类型是long（short） int类型的简称，sizeof(long) = sizeof(int) = 4。int和long的范围虽然一样,但输入输出格式不同,printf int的格式为%d，而printf long的格式为%ld。

 

考虑到程序的可移植性，还是要将他们区分开来。但当要求的数值范围为4byte时，建议使用int类型，因为第一版的C语言只有一种内置类型，那就是int。

 

long类型的位数总是和机器的指针位数相等。

 

字面值整数常量的类型默认为int或long，其精度类型取决于精度值，其值适合int型就是int型，比int型（INT_MAX）大的就是long类型。通过增加后缀可强制将字面值整数常量转换成long、unsigned或unsigned long类型。通过在数值后面添加L或l（推荐使用L，防l与1混淆）指定常量为long类型。例如128u，1L，1024UL，8Lu。没有short类型的字面值常量。

 

（12）在Win32 API及MFC中为了使类型名称在语意上更明了，对以上基本类型进行了大量的typedef。例如WINDEF.H中的BYTE,WORD,DWORD。

 

 

 
















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