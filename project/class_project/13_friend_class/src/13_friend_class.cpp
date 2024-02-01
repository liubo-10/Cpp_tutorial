/***********************************************************
 * @file name: 13_friend_class.cpp
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
    static int i;
    friend class B; // B可以直接访问A中的private的成员了
  public:
    static void set(int k) {
        i=k;
        i++;
    }
};

class B {
  public:
    static void ds(int l) {
        int *p=&A::i;
        cout<<"*p: "<<*p<<"\n";
        *p=1;
        cout<<"*p=1 *p: "<<*p<<"\n";
    }
};

int A::i=0;
void(*f1)(int)=&A::set;
void(*f2)(int)=&B::ds;

int main() {
    cout << "----------------begain------------------" << endl;

    f1(10);
    f2(20);	

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
*p: 11
*p=1 *p: 1
----------------end------------------

 * 
 */
