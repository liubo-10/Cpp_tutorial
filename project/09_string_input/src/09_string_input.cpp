/***********************************************************
 * @file name: 09_string_input.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "----------------begain------------------" << endl;
    string s,t; 
    cout<<"please input a string:"<<endl;
    cin>>s;
    t="I like programming!"; 
    cout<<"string output:"<<endl<<s<<endl<<t<<endl;
    cout<<s.append(" OK!")<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
 * 
 * 
 */
