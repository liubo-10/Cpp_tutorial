/***********************************************************
 * @file name: 28_try_catch_3.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<exception>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::logic_error;


int main() {
    cout << "----------------begain------------------" << endl;
    try {
        exception theError;
        throw(theError);
    }

    catch(const exception &theError) {
        cout<<theError.what()<<endl;
    }

    try {
        logic_error theLogicError("Logic Error!");	
        throw(theLogicError);
    }

    catch(const exception & theLogicError) {
        cout<<theLogicError.what()<<endl;	
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
std::exception
Logic Error!
----------------end------------------

 */
