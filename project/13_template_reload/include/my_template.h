/***********************************************************
 * @file name: my_template.h
 * @author: liubo
 * @date: 2024.01.29
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T> //模板参数由关键字typename（也可以使用class） 定义 定义一个函数模板 返回两个数中数值大的那一个 
inline T max(const T &a,const T &b) { // 函数有两个参数 ，类型为定义 
    cout << "\n----------------two value------------------" << endl;
    return a>b?a:b;
}
 
template <typename T> 
inline T max(const T &a,const T &b,const T &c) {
    cout << "\n----------------three const value------------------" << endl;
    T temp;
    if(a<b) {
        temp = b;
    }
    else {
        temp = a;
    }
    return temp >c?temp :c;
}

inline int max(const int &a,const int &b) {
    cout << "\n----------------two const value------------------" << endl;
    return a>b?a:b;
}
 
template <typename T,typename T1=double>
inline T max(const T &a,const T1 &b) {
    std::cout<<"template <typename T,typename T1=double> "<<std::endl;
    return a>b?a:b;
}









/**
 * @expected output:
 * 
 * 
 */
