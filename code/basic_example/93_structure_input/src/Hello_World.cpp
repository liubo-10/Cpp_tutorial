/***********************************************************
 * @file name: Hello_World.cpp
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

int main(){
    cout << "----------------begain------------------" << endl;


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
 */
