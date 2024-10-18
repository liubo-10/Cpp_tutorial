/***********************************************************
 * @file name: 05_reference.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h> // pause()头文件

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "----------------begain------------------" << endl;
    {
        int num=50;
        int &ref=num;
        ref+=10;
        cout<<"num="<<num<<endl;
        cout<<"ref="<<ref<<endl;
        num+=40;
        cout<<"num="<<num<<endl;
        cout<<"ref="<<ref<<endl; 
    }

    {
        int num;
        int &ref=num;
        num=5;
        cout<<"num="<<num<<endl;  
        cout<<"ref="<<ref<<endl; 
        cout<<"&num="<<&num<<endl; // 打印地址
        cout<<"&ref="<<&ref<<endl; 
    }

    cout << "----------------end------------------" << endl;
    //pause();
    cin.get();
    return EXIT_SUCCESS;
}


/**
 * @expected output:
 * 
 * 
 */
