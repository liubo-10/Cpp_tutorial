/***********************************************************
 * @file name: 01_STL_mystring_imp.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

class mystring {
    static int total_length;
    int length;
    char* contents;
  public:
    mystring(char *s) {
        length=strlen(s);
        contents=new char[length +1];
        strcpy(contents,s);
    }
    static int set_total_length(mystring&obj) {
        total_length+=obj.length;
        return total_length;
    }
    ~mystring() {
        delete[]contents;
    }
};

int mystring::total_length=0;

int main() {
    cout << "----------------begain------------------" << endl;
    mystring obj1((char*)"the first object");
    cout<<mystring::set_total_length(obj1)<<endl;
    mystring obj2((char*)"the second object");
    cout<<mystring::set_total_length(obj2)<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
----------------begain------------------
16
33
----------------end------------------

 */
