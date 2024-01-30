/***********************************************************
 * @file name: 11_overload.cpp
 * @author: liubo
 * @date: 2024.01.29
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

int add(int x,int y);
int add(int x,int y,int z);

int main() {
    cout << "----------------begain------------------" << endl;

    int a,b;
    a=add(5,10);
    b=add(5,10,20);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

int add(int x,int y) {
    int sum;
    sum=x+y;
    return sum;	
}

int add(int x,int y,int z) {
    int sum;
    sum=x+y+z;
    return sum;	
}

/**
 * @expected output:
 * 
 * 
 */
