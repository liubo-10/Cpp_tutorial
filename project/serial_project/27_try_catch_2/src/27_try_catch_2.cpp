/***********************************************************
 * @file name: 27_try_catch_2.cpp
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

int main() {
    cout << "----------------begain------------------" << endl;

    int i;
    char ch;
    cout<<"请输入一个整数和一个字符";
    try {
        cin>>i>>ch;
        if(i==0)  throw 0;
        if(ch=='!')  throw '!';	
    }
    catch(int) {
        cout<<"输入为0\n";	
    }
    catch(char) {
        cout<<"输入字符！";	
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:


 */
