/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-10-17
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  //包含输入/输出头文件
#include <stdio.h>   //包含C语言的库函数头文件
#include <string.h>  //包含字符串处理头文件

using std::cin;
using std::cout;
using std::endl;

class integer
{
   public:
    integer(int a)  // 转换构造函数,把int a 转换为类对象
    {
        i = a;
        printf("constructure :%d\r\n", i);
    }

    operator int()  // 类型转换函数,把类对象转换为整型数
    {
        printf("operator int :%d\r\n", i);
        return i;
    }

   private:
    int i;
};
/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - XXX XXX
 * |           - XXX XXX
 * |           - XXX XXX
 * | @return :
 * --------------
 * | @brief  : XXX
 * |           上例class可以在integer类对象与整型数之间相互转换。
 ******************************************************************************/
int main()
{
    printf("----------------begain------------------\n");

    integer i1(10), i2(20);  // 打印：constructure :10  constructure :20

    // 使用转换运算符函数,将类对象i1转换为int后,再进行赋值
    // i1  integer-->int 打印：operator int :10
    int a = i1;

    // 使用转换构造函数,将int a转换为integer类对象后赋给i1;
    // a  int-->integer 打印：constructure :10
    i1 = a;

    // 由于没有重载*运算符,所以首先把i1通过转换运算符函数转换为int后与2进行整数乘法运算,
    // 然后与整数10进行整数加法运算,最后使用转换构造函数把最终结果转换为integer类对象后赋给i2.
    // (1) i1 integer-->int (10 + i1 * 2) 打印：operator int :10
    // (2) (10 + i1 * 2) int-->integer i2 = 10 + i1 * 2 打印：constructure :30
    i2 = 10 + i1 * 2;

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
