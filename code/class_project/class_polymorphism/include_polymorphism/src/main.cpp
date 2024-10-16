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

class Point  // 定义基类Point
{
   private:
    float x, y;

   public:
    Point() {};
    Point(float i, float j)
    {
        x = i;
        y = j;
    }
    virtual float area()  // 声明为虚函数 虚函数的目的是告诉编译器在运行时才能确定要调用哪一个虚函数
    {
        return 0.0;
    }
};

const float Pi = 3.141593;
class Circle : public Point  // 定义派生类Circle
{
   private:
    float radius;

   public:
    Circle(float r)
    {
        radius = r;
    }
    virtual float area()  // 声明为虚函数 虚函数的目的是告诉编译器在运行时才能确定要调用哪一个虚函数
    {
        return Pi * radius * radius;
    }
};

class Point1  // 定义基类Point
{
   private:
    float x, y;

   public:
    Point1() {};
    Point1(float i, float j)
    {
        x = i;
        y = j;
    }
    float area()
    {
        return 0.0;
    }
};

class Circle1 : public Point1  // 定义派生类Circle
{
   private:
    float radius;

   public:
    Circle1(float r)
    {
        radius = r;
    }
    float area()
    {
        return Pi * radius * radius;
    }
};

/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - XXX XXX
 * |           - XXX XXX
 * |           - XXX XXX
 * | @return :
 * --------------
 * | @brief  : XXX
 * |           XXX
 ******************************************************************************/
int main()
{
    printf("----------------begain------------------\n");

    Point* pp;  // 指向基类的指针pp
    Circle c(5.4321);
    pp = &c;
    cout << pp->area() << endl;  // 调用虚函数, 执行派生类中定义的函数area()

    Point1* pp1;  // 指向基类的指针pp
    Circle1 c1(5.4321);
    pp1 = &c1;
    cout << pp1->area() << endl;  // 调用非虚函数, 执行基类中定义的函数area()

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/






        // 1   #include <iostream.h>
        // 2   class animal                                    //定义基类animal
        // 3   {
        // 4   public:
        // 5        void sleep()                               //定义成员函数
        // 6        {
        // 7            cout<<"animal sleep"<<endl;
        // 8        }
        // 9        void breathe()                             //定义成员函数
        // 10       {
        // 11           cout<<"animal breathe"<<endl;
        // 12       }
        // 13  };
        // 14  class fish:public animal                        //定义animal的公有派生类fish
        // 15  {
        // 16  public:
        // 17       void breathe()                             //定义同名成员函数
        // 18       {
        // 19           cout<<"fish bubble"<<endl;
        // 20       }
        // 21  };
        // 22  void main()
        // 23  {
        // 24       fish fh;                                   //创建对象
        // 25       animal *pAn=&fh;                          //定义对象指针指向对象fh
        // 26       pAn->breathe();                            //调用breathe函数
        // 27  }