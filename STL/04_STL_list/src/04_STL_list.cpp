/***********************************************************
 * @file name: 04_STL_list.cpp
 * @author: liubo
 * @date: 2024.01.25
 * @describe: 
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

int main(){
    cout << "----------------begain------------------" << endl;
    
    cout << "\n----------------list 测试------------------" << endl;
    list<int> mylist;

    for(int i=0; i<5; i++) {
        mylist.push_back(i);
    }
    
    cout << "mylist:";
    for (auto iter = mylist.begin(); iter != mylist.end(); iter++) {
        cout << " " << *iter;
    }
    cout << endl;
    cout << "mylist.size():" << mylist.size() << endl;
    cout << endl;

    // 调用erase()
    mylist.erase(mylist.begin());

    cout << "mylist.begin() erase:" << *mylist.begin() << endl;

    cout << "mylist erase:";
    for (auto iter = mylist.begin(); iter != mylist.end(); iter++) {
        cout << " " << *iter;
    }
    cout << endl;
    cout << "mylist.size() erase:" << mylist.size() << endl;



    cout << "\n----------------resize 测试------------------" << endl;




    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

