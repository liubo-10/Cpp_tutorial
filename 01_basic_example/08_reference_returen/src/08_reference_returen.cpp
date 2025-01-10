/***********************************************************
 * @file name: 08_reference_returen.cpp
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

float& fn2(float r);

int main() {
    cout << "----------------begain------------------" << endl;

    fn2(5.0)=12.4; // 段错误
    cout<<fn2(5.0)<<endl;   

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

float& fn2(float r) {
    float t;
    t=3.14*r*r;
    return t;	// reference to local variable ‘t’ returned
}


/**
 * @expected output:
 * 
 * 
 */
