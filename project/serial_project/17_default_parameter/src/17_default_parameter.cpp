/***********************************************************
 * @file name: 17_default_parameter.cpp
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
    void set(int m=5,int d=16,int y=1991) {
        month=m;day=d;year=y;	
    }
    void print() {
        cout<<month<<"/"<<day<<"/"<<year<<endl;	
    }
  private:
    int month;
    int day;
    int year;
};


int main() {
    cout << "----------------begain------------------" << endl;
    Tdate a,b,c;
    a.set(4,12,1996);
    b.set(3);
    c.set(8,10);
    a.print(); 
    b.print(); 
    c.print(); 

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
 * 
 * 
 */
