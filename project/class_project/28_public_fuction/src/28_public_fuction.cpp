/***********************************************************
 * @file name: 28_public_fuction.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class base {
public:
    void who() {
        cout<<"this is the class of base !"<<endl;
    }
};
class derive1:public base {
public:
    void who() {
        cout<<"this is the class of derive1!"<<endl;
    }
};
class derive2:public base {
public:
    void who() {
        cout<<"this is the class of derive2!"<<endl;
    }
};

int main() {
    cout << "----------------begain------------------" << endl;

    base obj1,*p;
    derive1 obj2;
    derive2 obj3;
    p=&obj1;
    p->who();
    p=&obj2;
    p->who();
    
    ((derive2 *)p)->who();
    obj2.who();
    obj3.who();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
this is the class of base !
this is the class of base !
this is the class of derive2!
this is the class of derive1!
this is the class of derive2!
----------------end------------------

 */
