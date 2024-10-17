/***********************************************************
 * @file name: 26_try_catch.cpp
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

void detail(int k) {
    cout<<"start of detail function.\n";
    if(k==0) {
        throw 123;
    }
    cout<<"end of detail function.\n";

}

void compute(int i) {
    cout<<"start of compute function.\n";
    detail(i);
    cout<<"end of compute function.\n";
}

int main() {
    cout << "----------------begain------------------" << endl;
    
    int x;
    cout<<"Enter x(0 will throw an exception):";
    cin>>x;
    try {
        compute(x);
    }
    catch(int i) {
       cout<<"exception:"<<i<<endl;
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:


 */
