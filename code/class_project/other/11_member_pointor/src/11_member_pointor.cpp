/***********************************************************
 * @file name: 11_member_pointor.cpp
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
    public:
    int i,*p;
    A() {
        i=10;p=&i;
    }
};

int A::*p = &A::i; //成员变量指针  成员类型 类名::*指针名=&类名::成员名;

int main() {
    cout << "----------------begain------------------" << endl;

    A aa,bb;	
    (bb.*p)++;
    -- *aa.p;
    cout<<"AA:"<<aa.*p<<" BB:"<<bb.*p<<"\n";
    cout<<"AA:"<<*aa.p<<" BB:"<<*bb.p<<"\n";

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
AA:9 BB:11
AA:9 BB:11
----------------end------------------


 * 
 */
