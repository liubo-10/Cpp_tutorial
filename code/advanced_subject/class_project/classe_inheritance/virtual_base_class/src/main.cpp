/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-10-13
 * --------------
 * | @brief   : test the order of virtual class build 
 ******************************************************************************/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class base  // 定义基类base
{
   protected:  // 定义基类保护成员
    int x;

   public:
    base(int x1)  // 定义基类构造函数
    {
        x = x1;
        cout << "constructing base,x=" << x << endl;
    }
};

class base1 : virtual public base  // 定义基类base1为虚基类
{
    int y;  // 定义虚基类私有成员
   public:
    base1(int x1, int y1) : base(x1)  // 定义虚基类base1的构造函数
    {
        y = y1;
        cout << "constructing base1,y=" << y << endl;
    }
};
class base2 : virtual public base  // 定义基类base2为虚基类
{
    int z;  // 定义虚基类私有成员
   public:
    base2(int x1, int z1) : base(x1)  // 定义虚基类base2的构造函数
    {
        z = z1;
        cout << "constructing base2,z=" << z << endl;
    }
};

class derived : public base1, public base2  // 定义多重继承的派生类
{
    int xyz;  // 定义派生类私有成员
   public:
    derived(int x1, int y1, int z1, int xyz1) : base(x1), base1(x1, y1), base2(x1, z1)
    // 派生类构造函数
    {
        xyz = xyz1;
        cout << "constrcting derived xyz=" << xyz << endl;
    }
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

    derived obj(1, 2, 3, 4);  // 创建派生类对象

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/





        1   #include<iostream.h>
        2   class base                                           //定义基类base
        3   {
        4   private:                                             //定义基类私有成员
        5        int x,y;
        6   public:
        7        base(int xx=0,int yy=0)                         //定义构造函数
        8        {
        9            x=xx;
        10           y=yy;
        11       }
        12       void disp()                                     //定义成员函数
        13       {
        14           cout<<"base: "<<x<<"   "<<y<<endl;
        15       }
        16  };
        17  class base1:public base                              //定义公有派生类base1
        18  {
        19  private:                                             //定义派生类base1私有成员
        20       int z;
        21  public:
        22       base1(int xx,int yy,int zz):base(xx,yy)         //定义派生类的构造函数
        23       {
        24           z=zz;
        25       }
        26       void disp()                                     //定义同名函数
        27       {
        28           cout<<"base1:"<<z<<endl;
        29       }
        30  };
        31  void main()
        32  {
        33       base obj(3,4),＊objp;                           //创建基类的对象和对象指针
        34       base1 obj1(1,2,3);                              //创建派生类的对象
        35       objp=&obj;                                      //对象指针指向基类
        36       objp->disp();                                   //调用基类成员函数
        37       objp=&obj1;                                     //对象指针指向派生类
        38       objp->disp();                                   //调用派生类成员函数
        39  }