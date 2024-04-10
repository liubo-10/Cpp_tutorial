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
  public:
    mystring() {
        length=256;
        contents=new char[length];
        cout<<"default constructor\n";
    }
    mystring(char *s) {
        length=strlen(s);
        contents=new char[length +1];
        strcpy(contents,s);
        cout<<"char constructor\n";
    }

    mystring(const mystring &s) {
        length=s.length;
        contents=new char[length];
        strcpy(contents,s.contents);
        cout<<"copy constructor\n";
    }
    ~mystring() {
        delete[]contents;
    }

    mystring operator +(const mystring&);
    void operator =(const mystring& s) {
        strcpy(contents,s.contents);
        cout<<"operator ="<<endl;
    }

    void display() {
        cout<<"The string is:"<<contents<<endl;
        cout<<"The length is:"<<length<<endl;
    }
    static int set_total_length(mystring&obj) {
        total_length+=obj.length;
        return total_length;
    }

  private:
    static int total_length;
    int length;
    char* contents;
};

mystring mystring::operator +(const mystring& a) {
    cout<<"operator +"<<endl;
    mystring s;
    strcpy(s.contents,contents);
    strcat(s.contents,a.contents);
    s.display();
    cout<<&s<<endl;
    return s;
}

int mystring::total_length=0;

int main() {
    cout << "----------------begain------------------" << endl;
    cout << "----------------total_length------------------" << endl;
    mystring obj1((char*)"the first object");
    cout<<mystring::set_total_length(obj1)<<endl;
    mystring obj2((char*)"the second object");
    cout<<mystring::set_total_length(obj2)<<endl;

    cout << "----------------operator +------------------" << endl;
    mystring demo1((char*)"Visual C++ ");
    mystring demo2((char*)"6.0 ");
    demo1.display();
    demo2.display();

    cout << "----------------demo3------------------" << endl;
    mystring demo3=demo1+demo2; // demo3没有被构造，直接拷贝s地址
    demo3.display();
    cout<<&demo3<<endl;

    cout << "----------------demo4------------------" << endl;
    mystring demo4=demo3+(char*)"Programming.";
    demo4.display();

    cout << "----------------operator =------------------" << endl;
    mystring demo5=demo4;
    demo5.display();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
----------------total_length------------------
char constructor
16
char constructor
33
----------------operator +------------------
char constructor
char constructor
The string is:Visual C++ 
The length is:11
The string is:6.0 
The length is:4
----------------demo3------------------
operator +
default constructor
The string is:Visual C++ 6.0 
The length is:256
0x7ffd96781b50
The string is:Visual C++ 6.0 
The length is:256
0x7ffd96781b50
----------------demo4------------------
char constructor
operator +
default constructor
The string is:Visual C++ 6.0 Programming.
The length is:256
0x7ffd96781b60
The string is:Visual C++ 6.0 Programming.
The length is:256
----------------operator =------------------
copy constructor
The string is:Visual C++ 6.0 Programming.
The length is:256
----------------end------------------



 */
