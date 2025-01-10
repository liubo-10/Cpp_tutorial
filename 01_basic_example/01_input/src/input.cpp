/*****************************************************************************
 * | @file    : input.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-01-28
 * --------------
 * | @brief   : main
 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

int main(){
    printf("--------------------begain-------------------\n");

    char name[10];
    int age;
    cout<<"please input your name:";	
    cin>>name;
    cout<<"how old are you:";
    cin>>age;
    cout<<"the name is "<<name<<endl;
    cout<<"the age  is "<<age<<endl;

    printf("--------------------end----------------------\n");
    // getchar();

    pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
