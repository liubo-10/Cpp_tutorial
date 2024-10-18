/***********************************************************
 * @file name: 06_operator_double.cpp
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

class RMB {
  public:
    RMB(double value=0.0);

    operator double() { // 定义了一个将类转化为double的转换函数
        return yuan+fen/100.0;
    }

    void print() {
        cout<<"yuan: "<<yuan<<" fen: "<<fen<<endl;	
    }


    void display() {
        cout<<(yuan+fen/100.0)<<endl;
    }
  protected:
    unsigned int yuan;
    unsigned int fen;
};

RMB::RMB(double value) {
    yuan=value;  // 舍去小数
    fen=(value-yuan)*100+0.5; // +0.5四舍五入
}

int main() {
    cout << "----------------begain------------------" << endl;
    
    RMB d1(2.0),d2(1.5),d3;
    d1.print();
    d2.print();

    cout<<"(double)d1: "<<(double)d1<<" (double)d2: "<<(double)d2<<endl;	

	d3=RMB((double)d1+(double)d2);
    d3.print();

	d3=d1+d2;
    d3.print();

	d3.display();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
yuan: 2 fen: 0
yuan: 1 fen: 50
(double)d1: 2 (double)d2: 1.5
yuan: 3 fen: 50
yuan: 3 fen: 50
3.5

 */
