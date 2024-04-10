/***********************************************************
 * @file name: 07_statistic_garde.cpp
 * @author: liubo
 * @date: 2024.01.28
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

int array[6][4]={{60, 80,90,75},
                 {75, 85,65,77},
                 {80, 88,90,98},
                 {89,100,78,81},
                 {62, 68,69,75},
                 {85, 85,77,91}};

int& level(int grade[],int size,int& tA,int& tB );

int main() {
    cout << "----------------begain------------------" << endl;
    int typeA=0,typeB=0;
    int student=6;
    int gradesize=4;
    for(int i=0;i<student;i++) {
        level(array[i],gradesize,typeA,typeB)++;
    }
    cout<<"number of type A is "<<typeA<<endl;
    cout<<"number of type B is "<<typeB<<endl; 

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

int &level(int grade[],int size,int& tA,int& tB) { // 数组名作函数形参
    int sum=0;
    for(int i=0;i<size;i++) {
        sum+=grade[i];
    }
    sum/=size;
    if(sum>=80) {
        return tA;
    } else {
        return tB;
    }	
}


/**
 * @expected output:
 * 
 * 
 */
