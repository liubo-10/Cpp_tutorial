/***********************************************************
 * @file name: 17_multiple_inherit.cpp
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

class data {
  public:
    data(int x) {
        x=x;
        cout<<"class data\n";
    }
  private:
    int x;
};
class a {
  public:
    a(int x):
    d1(x) {
        cout<<"class a\n";
    }
  private:
    data d1;
};
class b:public a {
  public:
    b(int x):
    a(x),d2(x) {
        cout<<"class b\n";
    }
  private:
    data d2;
};
class c:public b {
  public:
    c(int x):b(x) {
        cout<<"class c\n";
    }
};

int main() {
    cout << "----------------begain------------------" << endl;

    c object(5);

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
class data
class a
class data
class b
class c
----------------end------------------
 * 
 */
