/***********************************************************
 * @file name: 05_copy_structure.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

class Person {
  public:
    Person(char* na) {
        cout<<"call constructor"<<endl;
        name=new char[strlen(na)+1];
        if(name!=0) {
            strcpy(name,na);
        }
    }
    Person(Person& p) {
        cout<<"call copy constructor"<<endl;
        name=new char[strlen(p.name)+1];
        if(name!=0) {
            strcpy(name,p.name);
        }
    }
    void printname() {
        cout<<name<<endl;
    }
    ~Person() {
        delete name;
    }
  private:
    char* name;
};


int main() {
    cout << "----------------begain------------------" << endl;
    
    Person wang((char*)"wang");
    Person li(wang);
    wang.printname();
    li.printname();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
call constructor
call copy constructor
wang
wang
 */


