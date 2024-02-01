/***********************************************************
 * @file name: 16_cout_test.cpp
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
    for(int i=1;i<=10;i++) {
     for(int j=1;j<=i;++j) {
        cout<<"M";
     }
        cout<<endl;
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
M
MM
MMM
MMMM
MMMMM
MMMMMM
MMMMMMM
MMMMMMMM
MMMMMMMMM
MMMMMMMMMM
 */
