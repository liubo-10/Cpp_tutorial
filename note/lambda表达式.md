* 👋 Hi, I’m bliu2-10
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# lambda表达式

Lambda有很多叫法，有Lambda表达式、Lambda函数、匿名函数

lambda表达式是在调用或作为函数参数传递的位置处定义匿名函数对象的便捷方法。通常，lambda用于封装传递给算法或异步方法的几行代码。



### 语法定义



```c++
[capture list](parameters)mutable throw()->teturn type{statement}
```



1. capture list 

   捕获列表。在C++规范中也称为Lambda导入器， 捕获列表总是出现在Lambda函数的开始处。实际上，`[]`是Lambda引出符。编译器根据该引出符判断接下来的代码是否是Lambda函数，捕获列表能够捕捉上下文中的变量以供Lambda函数使用。

2. parameters

   参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号“()”一起省略。

3. mutable

   可变规格。修饰符， 默认情况下l/ambda函数总是一个const函数，mutable可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。

4. 异常说明。用于Lamdba表达式内部函数抛出异常。

5. 返回类型。 追踪返回类型形式声明函数的返回类型。我们可以在不需要返回值的时候也可以连同符号”->”一起省略。此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。

6. lambda函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。




















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
