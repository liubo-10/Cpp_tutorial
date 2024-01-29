/***********************************************************
 * @file name: 06_reference_parameter.cpp
 * @author: liubo
 * @date: 2024.01.28
 * @describe: 引用作函数的形参，实际上是在被调函数中对实参变量进行操作。
 * 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

void swap(int &x,int &y);

int main() {
    cout << "----------------begain------------------" << endl;
    int x=5,y=6; 
    cout<<"before swap, x:"<<x<<" ,y:"<<y<<endl; 
    swap(x,y);
    cout<<"after  swap, x:"<<x<<" ,y:"<<y<<endl;

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

void swap(int &rx,int &ry) {
    int t=rx;
    rx=ry;
    ry=t;	
}

/**
 * @expected output:
 * 
 * 
 */
