/***********************************************************
 * @file name: 07_STL_set.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: set容器指针实现
 * 
 * 
 **********************************************************/
#include<iostream>
#include"STL_set.h"

int main() {
    cout << "----------------begain------------------" << endl;
    Set s1,s2,s3;

    s1.AddElem(10);
    s1.AddElem(20);
    s1.AddElem(30);
    s1.AddElem(40);
    s2.AddElem(30);
    s2.AddElem(50);
    s2.AddElem(10);
    s2.AddElem(60);
    cout<<"s1=";s1.Print();
    cout<<"s2=";s2.Print();

    s2.RmvElem(50);
    cout<<"s2-{50}=";
    s2.Print();

    if(s1.Member(20)) {
        cout<<"20 is in s1\n";
    }

    s1.Intersect(&s2,&s3);
    cout<<"s1 intsec s2=";
    s3.Print();

    s1.Union(&s2,&s3);
    cout<<"s1 union s2=";
    s3.Print();

    if(!s1.Equal(&s2)) {
        cout<<"s1!=s2\n";
    }

    cout << "\n----------------Union test------------------" << endl;
    for(int i=0; i<16; i++){
        s1.AddElem(i);
    }
    cout<<"s1=";s1.Print();
    
    s1.Union(&s2,&s3);
    cout<<"s1 union s2=";
    s3.Print();



    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
s1={10;20;30;40;}
s2={30;50;10;60;}
s2-{50}{30;10;60;}
20 is in s1
s1 intsec s2={10;30;}
s1 union s2{30;10;60;20;40;}
s1!=s2
----------------end------------------
 */
