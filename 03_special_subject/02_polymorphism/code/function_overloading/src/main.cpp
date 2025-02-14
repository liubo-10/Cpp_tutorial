/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  //包含输入/输出头文件
#include <stdio.h>   //包含C语言的库函数头文件
#include <string.h>  //包含字符串处理头文件

using std::cin;
using std::cout;
using std::endl;

class point  // 定义基类point
{
   public:
    point() {}             // 声明构造函数
    point(int xx, int yy)  // 重载构造函数 定义基类构造函数
    {
        x = xx;
        y = yy;
    }
    double area()  // 定义基类的成员函数
    {
        return 0.0;
    }

   private:
    int x, y;
};

class circle : public point  // 派生类公有继承于基类
{
   public:
    circle() {}                                     // 声明构造函数
    circle(int xx, int yy, int rr) : point(xx, yy)  // 重载构造函数 定义派生类构造函数
    {
        r = rr;
    }
    double area()  // 同名函数
    {
        return 3.1416 * r * r;
    }

   private:
    int r;
};

/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - cmd 命令码
 * |           - dataPtr 发送的数据
 * |           - Len 发送的数据长度
 * | @return :
 * --------------
 * | @brief  : 发送请求到智能电池
 * |           通过串口2发送
 ******************************************************************************/
int main()
{
    printf("----------------begain------------------\n");

    point pob(15, 15);                                            // 创建基类对象
    circle cob(20, 20, 10);                                       // 创建派生类对象
    cout << "pob.area()=  " << pob.area() << endl;                // 调用基类成员函数
    cout << "cob.area()=  " << cob.area() << endl;                // 调用派生类成员函数
    cout << "cob.point::area()=  " << cob.point::area() << endl;  // 派生类对象调用基类成员函数

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
