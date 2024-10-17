/***********************************************************
 * @file name: 22_virtual_inherit.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 *  如果一个派生类有多个直接基类，而这些直接基类又有一个共同的基类，
 *  则在最终的派生类中会保留该间接共同基类成员的多份同名成员。
 *  这种情况有时也是有可能出现的，还增加了访问这些成员时的困难，容易出错。
 *  为了解决这个问题，可以使用虚基类的方法。
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class base {
  public:
    base() {
        cout<<"this is base class!\n";
    }
};
class base2 {
  public:
    base2() {
        cout<<"this is base2 class!\n";
    }
};
class level1:public base2,virtual public base { // base不会构建，base2会构建
  public:
    level1() {
        cout<<"this is level1 class!\n";
    }
};
class level2:public base2,virtual public base {
  public:
    level2() {
        cout<<"this is level2 class!\n";
    }
};
class toplevel:public level1,virtual public level2 { // 先构建level2
  public:
    toplevel() {
        cout<<"this is toplevel class!\n";
    }
};

int main() {
    cout << "----------------begain------------------" << endl;

    toplevel topobj;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
this is base class!
this is base2 class!
this is level2 class!
this is base2 class!
this is level1 class!
this is toplevel class!
----------------end------------------

 */
