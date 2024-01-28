/***********************************************************
 * @file name: 01_new_delete.cpp
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

int main(){
    cout << "----------------begain------------------" << endl;
    cout << "\n----------------new 测试------------------" << endl;
    int *p1;
    // p=new int;
    // *p=5;
    p1=new int(5);
    cout<<*p1;
    delete p1;

    cout << "\n----------------动态申请内存 测试------------------" << endl;

    int *p;
    int n;
    cout<<"please input the length of the array: ";
    cin>>n;
    if((p=new int[n])==0) {
        cout<<"can't allocate more memory, terminating"<<endl;
        exit(1);	
    }
    for(int i=0;i<n;i++) {
       p[i]=i*2;
    }

    cout<<"Now output the array: "<<endl;

    for(i=0;i<n;i++) {
        cout<<p[i]<<"  "<<endl;
    }
    delete []p;

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}


/**
 * @expected output:
 * 
 * 
 */


