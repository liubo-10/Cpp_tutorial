/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-10-13
 * --------------
 * | @brief   : main
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
