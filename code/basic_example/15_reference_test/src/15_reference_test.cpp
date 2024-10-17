/***********************************************************
 * @file name: 15_reference_test.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "----------------begain------------------" << endl;

    int i=0,&l=i,&k=l;
    i=++l-k;
    cout<<"i="<<i<<endl;  

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
 * 
 * 
 */
