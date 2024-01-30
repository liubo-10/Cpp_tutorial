/***********************************************************
 * @file name: 13_template_reload.cpp
 * @author: liubo
 * @date: 2024.01.29
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include"my_template.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "----------------begain------------------" << endl;
    max(1,2,3);       // max(const T &a,const T &b,const T &c) max<int>
    max(1.0,2.3);     // max(const T &a,const T &b) max<double>
    max('a','b');     // max(const T &a,const T &b)  max<char>
    max(1,2);         // inline int max(const int &a,const int &b)
    max<>(1,2);       // max(const T &a,const T &b) max<int>
    max<int>(1,2);    // max(const T &a,const T &b) max<int>
    max('a',2);       // inline int max(const int &a,const int &b)

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
 * ----------------three const value------------------

----------------two value------------------

----------------two value------------------

----------------two const value------------------

----------------two value------------------

----------------two value------------------
template <typename T,typename T1=double> 
 * 
 */
