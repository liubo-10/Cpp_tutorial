/***********************************************************
 * @file name: 03_iostream.cpp
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

    cout << "\n----------------空格输入 测试------------------" << endl;
    float  a;
    int  i1,i2;
    char  ch1,ch2;
    cin>>i1>>a>>i2>>ch1>>ch2; 

    cout<<"i1:"<<i1<<"  a:"<<a<<"  i2:"<<i2<<"  ch1:"<<ch1<<"  ch2:"<<ch2<<endl;
    // 输入：34  5.678  1a  b<CR>
    // 输出：i1:34  a:5.678  i2:1  ch1:a  ch2:b

    cout << "\n----------------结构体输入 测试------------------" << endl;


    struct student {
        int    no;
        float 	math;
    };
    int n;
    cin>>n;
    student wang;
    wang.no=n;
    cin>>wang.math;
    cout<<wang.no<<" "<<wang.math<<endl;


    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}













/**
 * @expected output:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */



