/***********************************************************
 * @file name: 12_member_pointor02.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class A {
    int i;
    public:
    int set(int k) {
        i=++k;
        return i;	
    }
};

int main() {
    cout << "----------------begain------------------" << endl;

    int(A::*f)(int)=&A::set; // 函数成员指针
    A aa;
    cout<<(aa.*f)(10)<<endl; // 11

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
 * 
 * 
 */
