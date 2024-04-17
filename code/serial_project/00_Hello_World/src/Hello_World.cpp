/***********************************************************
 * @file name: Hello_World.cpp
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

int main()
{
    cout << "----------------begain------------------" << endl;

    /**
     * In this example a single XML contains multiple <BehaviorTree>
     * To determine which one is the "main one", we should first register
     * the XML and then allocate a specific tree, using its ID */

    cout<<"Hello World!"<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:


 */
