/***********************************************************
 * @file name: 12_template.cpp
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

template<class T>
T min(T a[],int n) {
    int i;
    T minv=a[0];
    for(i=1;i<n;i++) {
        if(minv>a[i]) {
            minv=a[i];
        }
    }
    return minv;	
}

int main() {
    cout << "----------------begain------------------" << endl;
    int a[]={1,3,0,2,7,6,4,5,2};
    double b[]={1.2,-3.4,6.8,9.8};
    int c[]={1,9,5,-6,7,8};
    cout<<"a de shuzu zhong min zhi wei:"<<min(a,9)<<endl; // 隐式指定T的类型
    cout<<"b de shuzu zhong min zhi wei:"<<min(b,4)<<endl; 
    cout<<"c de shuzu zhong min zhi wei:"<<min(c,6)<<endl; 

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}


/**
 * @expected output:
 * 
 * 
 */
