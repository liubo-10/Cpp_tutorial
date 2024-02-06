/***********************************************************
 * @file name: 23_inherit_destruction.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class OBJ1 {
  public:
    OBJ1() {
        cout<<"OBJ1\n";
    }
    ~OBJ1() {
        cout<<"destructing OBJ1"<<endl;
    }
};

class OBJ2 {
  public:
    OBJ2() {
        cout<<"OBJ2\n";
    }
    ~OBJ2() {
        cout<<"destructing OBJ2"<<endl;
    }
};

class Base1 {
  public:
    Base1() {
        cout<<"Base1\n";
    }
    ~Base1() {
        cout<<"destructing Base1"<<endl;
    }
};

class Base2 {
  public:
    Base2() {
        cout<<"Base2\n";
    }
    ~Base2() {
        cout<<"destructing Base2"<<endl;
    }
};

class Base3 {
  public:
    Base3() {
        cout<<"Base3\n";
    }
    ~Base3() {
        cout<<"destructing Base3"<<endl;
    }
};

class Base4 {
  public:
    Base4() {
        cout<<"Base4\n";
    }
    ~Base4() {
        cout<<"destructing Base4"<<endl;
    }
};

class Derived:public Base1, public Base3, virtual public Base2, virtual public Base4 {
  public:
    Derived():
    Base2(),Base4(),Base1(),Base3(),obj2(),obj1() { // 先虚后实
        cout<<"Derived ok.\n";
    }
    ~Derived() {
        cout<<"destructing Drived"<<endl;
    }
  protected:
    OBJ1 obj1;
    OBJ2 obj2;
};
int main() {
    cout << "----------------begain------------------" << endl;

    Derived aa;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
Base2
Base4
Base1
Base3
OBJ1
OBJ2
Derived ok.
----------------end------------------
destructing Drived
destructing OBJ2
destructing OBJ1
destructing Base3
destructing Base1
destructing Base4
destructing Base2

 */
