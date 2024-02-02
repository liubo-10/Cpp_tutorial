/***********************************************************
 * @file name: 14_template_reload01.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define PI 3.1415926535
#define CS Circle_Square

template<class T>
double Circle_Square(T x) {
    cout << "\n----------------template------------------" << endl;

    return x*x*PI;	
}
double Circle_Square(long x) {
    cout << "\n----------------fuction------------------" << endl;

    return x*x*PI;	
}

int main() {
    cout << "----------------begain------------------" << endl;
    int      r1=1;
    double   r2=2.0;
    long     r3=3;
    cout<<"The first cs is " <<CS(r1)<<endl; 
    cout<<"The second cs is "<<CS(r2)<<endl; 
    cout<<"The third cs is " <<CS(r3)<<endl; 

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:

----------------begain------------------
The first cs is 
----------------template------------------
3.14159
The second cs is 
----------------template------------------
12.5664
The third cs is 
----------------fuction------------------
28.2743
----------------end------------------

 */
