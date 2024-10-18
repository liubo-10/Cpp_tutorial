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

template <typename T>
T min(T a[], int n)
{
    int i;
    T minv = a[0];
    for (i = 1; i < n; i++) {
        if (minv > a[i]) {
            minv = a[i];
        }
    }
    return minv;
}

template <typename T>  // 定义模板
const T& min(const T& t1, const T& t2)
{
    return t1 > t2 ? t2 : t1;  // 返回较小值
}

template <typename T>  // 定义模板
const T& max(const T& t1, const T& t2)
{
    return t1 > t2 ? t1 : t2;  // 返回较大值
}

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

    int a[] = {1, 3, 0, 2, 7, 6, 4, 5, 2};
    double b[] = {1.2, -3.4, 6.8, 9.8};
    int c[] = {1, 9, 5, -6, 7, 8};
    cout << "the min value of a is:" << min(a, 9) << endl;  // 隐式指定T的类型
    cout << "the min value of b is:" << min(b, 4) << endl;
    cout << "the min value of c is:" << min(c, 6) << endl;

    int x, y;  // 定义整型变量
    int mn, mx;
    cout << "Please input 2 numbers:" << endl;
    cin >> x >> y;   // 接收用户输入
    mn = min(x, y);  // 调用函数
    cout << "The Min is :" << mn << endl;
    mx = max(x, y);  // 调用函数
    cout << "The Max is :" << mx << endl;

    printf("-----------------end-------------------\n");
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
