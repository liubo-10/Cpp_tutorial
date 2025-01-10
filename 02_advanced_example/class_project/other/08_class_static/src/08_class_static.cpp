/***********************************************************
 * @file name: 08_class_static.cpp
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
  public:
    A() {
       i++;	
    }
    int list() {
        return i;
    }
};

int A::i=0;

int main() {
    cout << "----------------begain------------------" << endl;

    A a1,a2,a3;
    cout<<a1.list()<<","<<a2.list()<<","<<a3.list()<< endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
3,3,3
----------------end------------------
 * 
 */
