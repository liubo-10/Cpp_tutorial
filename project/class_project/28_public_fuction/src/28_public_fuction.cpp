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



class base2
{
public:
    virtual void f1()
    {
       cout<<"f1 function of base"<<endl;
    }
    virtual void f2()
    {
       cout<<"f2 function of base"<<endl;
    }
    virtual void f3()
    {
       cout<<"f3 function of base"<<endl;
    }
    virtual void f4()
    {
       cout<<"f4 function of base"<<endl;
    }
};
class derive22:public base2
{
    void f1()
    {
       cout<<"f1 function of derive!"<<endl;
    }
    void f2(int x)
    {
       cout<<"f2 function of derive!"<<endl;
    }
    void f3()
    {
       cout<<"f3 function of derive!"<<endl;
    }
    void f4()
    {
       cout<<"f4 function of derive!"<<endl;
    }
};


int main() {
    cout << "----------------begain------------------" << endl;

    base obj1,*p;
    derive1 obj2;
    derive2 obj3;
    p=&obj1;
    p->who(); //base为实函数调用base
    p=&obj2;
    p->who();
    
    ((derive2 *)p)->who();
    obj2.who();
    obj3.who();


    base2 obj12,*ptr;
    derive22 obj22;
    ptr=&obj12;
    ptr->f1();
    ptr->f2();
    ptr->f3();
    ptr->f4();
    ptr=&obj22;
    ptr->f1(); //base为虚函数调用 derive
    ptr->f2();
    ptr->f3();
    ptr->f4();

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
f1 function of base
f2 function of base
f3 function of base
f4 function of base
f1 function of derive!
f2 function of base
f3 function of derive!
f4 function of derive!
----------------end------------------

 */
