/***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * @expected output:
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

int main(){
    cout << "----------------begain------------------" << endl;

    cout<<"Hello World!"<<endl;

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

#include "iostream"
using namespace std;
void main()
  {  
     int *p;
     p=new int;
     *p=5;
     /*p=new int(5);*/
     cout<<*p;
     delete p;
  }