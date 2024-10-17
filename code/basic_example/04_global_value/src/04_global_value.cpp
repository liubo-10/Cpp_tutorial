/***********************************************************
 * @file name: 04_global_value.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

float a=2.4;

int main(){
    cout << "----------------begain------------------" << endl;
    cout << "\n----------------global 测试------------------" << endl;
    int a=8;
    cout<<"  a: "<<a<<endl;
    cout<<"::a: "<<::a<<endl;  

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
    
}


/**
 * @expected output:
 * 
 * 
 */
