/*****************************************************************************
 * | @file    : test_class.hpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-10-13
 * --------------
 * | @brief   : CPP template
 ******************************************************************************/
#ifndef _TEST_CLASS_HPP_
#define _TEST_CLASS_HPP_

class A  // 父类
{
   private:
    int privatedateA;

   protected:
    int protecteddateA;

   public:
    int publicdateA;
};
//
class B : public A  // 基类A的派生类B（共有继承）
{
   public:
    void funct()
    {
        int b;
        b = privatedateA;    // error：基类中私有成员在派生类中是不可见的
        b = protecteddateA;  // ok：基类的保护成员在派生类中为保护成员
        b = publicdateA;     // ok：基类的公共成员在派生类中为公共成员
    }
};
//
class C : private A  // 基类A的派生类C（私有继承）
{
   public:
    void funct()
    {
        int c;
        c = privatedateA;    // error：基类中私有成员在派生类中是不可见的
        c = protecteddateA;  // ok：基类的保护成员在派生类中为私有成员
        c = publicdateA;     // ok：基类的公共成员在派生类中为私有成员
    }
};
//
class D : protected A  // 基类A的派生类D（保护继承）
{
   public:
    void funct()
    {
        int d;
        d = privatedateA;    // error：基类中私有成员在派生类中是不可见的
        d = protecteddateA;  // ok：基类的保护成员在派生类中为保护成员
        d = publicdateA;     // ok：基类的公共成员在派生类中为保护成员
    }
};

#endif  // #ifndef _TEST_CLASS_HPP_

/***********************************************************
 * end of file
 **********************************************************/
