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

    delete a;         // 之调用 Base 的析构函数
    delete b;

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
