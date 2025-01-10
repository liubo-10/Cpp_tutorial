/***********************************************************
 * @file name: 16_class_test.cpp
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

class Tdate {
  public:
    void set(int,int,int);
    int isLeapYear();
    void print();
  private:
    int month;
    int day;
    int year;
};

void Tdate::set(int m,int d,int y) {
    month=m;day=d;year=y;	
}
int Tdate::isLeapYear() {
    return((year%4==0&&year%100!=0)||(year%400==0));
}
void Tdate::print() {
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}

void someFunc(Tdate& refs) {
    refs.print();
    if(refs.isLeapYear()) {
        cout<<"right"<<endl;
    } else {
        cout<<"error"<<endl;
    }
}

int main() {
    cout << "----------------begain------------------" << endl;
    Tdate x;
    x.set(10,23,2000);
    x.print();
    someFunc(x);

    cout << "\n----------------class pointor------------------" << endl;
    Tdate s,*pTdate=&s;
    s.set(2,15,1998);
    pTdate->print();
    if((*pTdate).isLeapYear()) {
        cout<<"right"<<endl;
    } else {
        cout<<"error"<<endl;
    }
    someFunc(s);

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
2/15/1998
0
right
2/15/1998
0
right

 */
