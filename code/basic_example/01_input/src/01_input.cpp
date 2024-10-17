/***********************************************************
 * @file name: 01_input.cpp
 * @author: liubo
 * @date: 2024.01.28
 * @describe: 
 * 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

int main(){
    cout << "----------------begain------------------" << endl;
    cout << "\n----------------name输入 测试------------------" << endl;
    char name[10];
    int age;
     cout<<"please input your name:";	
     cin>>name;
     cout<<"how old are you:";
     cin>>age;
     cout<<"the name is "<<name<<endl;
     cout<<"the age  is "<<age<<endl;

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

/**
 * @expected output:
 * 
 * 
 */



