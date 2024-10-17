/***********************************************************
 * @file name: 26_class_operator.cpp
 * @author: liubo
 * @date: 2024.02.07
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class RMB {
  public:
    RMB(unsigned int d,unsigned int c);
    RMB operator +(RMB&);
    RMB& operator ++();
    void display() {
        cout<<(yuan+jf/100.0)<<endl;
    }
  protected:
    unsigned int yuan;
    unsigned int jf;
};

RMB::RMB(unsigned int d,unsigned int c) {
    yuan=d;
    jf=c;
    while(jf>=100) {
        yuan++;
        jf-=100;
    }
}

RMB RMB::operator +(RMB& s) {
    unsigned int c=jf+s.jf;
    unsigned int d=yuan+s.yuan;
    RMB result(d,c);
    return result;
}

RMB& RMB::operator ++() {
    jf++;
    if(jf>=100) {
        jf-=100;
        yuan++;
    }
    return *this;
}

int main() {
    cout << "----------------begain------------------" << endl;

    RMB d1(1,60);
    RMB d2(2,50);
    RMB d3(0,0);
    d3=d1+d2;
    d3.display();
    ++d3;
    d3.display();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
4.1
4.11
----------------end------------------

 */
