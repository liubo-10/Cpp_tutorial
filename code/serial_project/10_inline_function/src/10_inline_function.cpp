/***********************************************************
 * @file name: 10_inline_function.cpp
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

inline double circumference(double radius);

int main() {
    cout << "----------------begain------------------" << endl;

    double r = 3.0,s;
    s = circumference(r);
    cout << "the circumference is " << s << "." << endl;  

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

inline double circumference(double radius) {
    return 2*3.1415926*radius;	
}


/**
 * @expected output:
 * 
 * 
 */
