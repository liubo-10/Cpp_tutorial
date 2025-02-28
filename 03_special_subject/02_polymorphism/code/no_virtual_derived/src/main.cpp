/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

#include <iostream>  // 包含输入和输出操作

using std::cin;
using std::cout;
using std::endl;

class Base
{
   public:
    ~Base()
    {  // 虚析构函数
        cout << "Base destructor called!" << endl;
    }
};

class Derived : public Base
{
   public:
    ~Derived()
    {
        cout << "Derived destructor called!" << endl;
    }
};

int main()
{
    printf("--------------------begain-------------------\n");
    Base* a = new Derived();  // 基类指针指向派生类对象
    Derived* b = new Derived();

    delete a;         // 只调用 Base 的析构函数，无法调用子类虚构函数
    delete b;         // 调用 Derived 的析构函数，然后调用 Base 的析构函数

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/

#include <iostream.h>
class Rational
{
   public:
    Rational(int d, int n)  // 构造函数
    {
        den = d;
        num = n;
    }
    operator double();  // 类型强制转换成员函数的声明
   private:
    int den;  // 分数的分子
    int num;  // 分数的分母
};
Rational::operator double()  // 类型强制转换成员函数的定义
{
    return double(den) / double(num);  // 返回double类型的分数值
}
void main()
{
    Rational r(5, 8);
    double d = 4.7;
    d += r；  // 隐式调用类型转换成员函数，也可以使用显式调用：d+=double(r);
    cout << d << endl;  // 输出结果为5.325
}
