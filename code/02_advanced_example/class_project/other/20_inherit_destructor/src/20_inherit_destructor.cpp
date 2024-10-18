/***********************************************************
 * @file name: 20_inherit_destructor.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class person {
  public:
    person() {
        cout<<"the constructor of class persons!\n";
    }
    ~person() {
        cout<<"the destructor of class persons!\n";
    }
  private:
    char *name;
    int age;
    char add;
};
class student:public person {
  public:
    student() {
        cout<<"the constructor of class student!\n";
    }
    ~student() {
        cout<<"the destructor of class student!\n";
    }
  private:
    char *department;
    int level;
};
class teacher:public person {
  public:
    teacher() {
        cout<<"the constructor of class teacher!\n";
    }
    ~teacher() {
        cout<<"the destructor of class teacher!\n";
    }
  private:
    char *major;
    float salary;
};
int main() {
    cout << "----------------begain------------------" << endl;

    student d1;
    teacher d2;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
the constructor of class persons!
the constructor of class student!
the constructor of class persons!
the constructor of class teacher!
----------------end------------------
the destructor of class teacher!
the destructor of class persons!
the destructor of class student!
the destructor of class persons!

 */
