/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-09-01
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include "test_class.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
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
    B objB;
    a = objB.privatedateA;    // error：基类中私有成员在派生类中是不可见的,对对象不可见
    a = objB.protecteddateA;  // error：基类的保护成员在派生类中为保护成员，对对象不可见
    a = objB.publicdateA;     // ok：基类的公共成员在派生类中为公共成员，对对象可见

    C objC;
    a = objC.privatedateA;    // error：基类中私有成员在派生类中是不可见的,对对象不可见
    a = objC.protecteddateA;  // error：基类的保护成员在派生类中为私有成员，对对象不可见
    a = objC.publicdateA;     // error：基类的公共成员在派生类中为私有成员，对对象不可见

    D objD;
    a = objD.privatedateA;    // error：基类中私有成员在派生类中是不可见的,对对象不可见
    a = objD.protecteddateA;  // error：基类的保护成员在派生类中为保护成员，对对象不可见
    a = objD.publicdateA;     // error：基类的公共成员在派生类中为保护成员，对对象不可见

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/***********************************************************
 * end of file
 **********************************************************/

