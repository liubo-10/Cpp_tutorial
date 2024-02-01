/***********************************************************
 * @file name: 10_class_static_pointor.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

class Student {
  public:
    Student(char *pName);
    ~Student();
  protected:
    static Student* pFirst;
    Student *pNext;
    char name[40];
};

Student* Student::pFirst=nullptr;

Student::Student(char *pName) {
    strncpy(name,pName,sizeof(name));
    name[sizeof(name)-1]='\0';
    pNext=pFirst;
    pFirst=this;
}

Student::~Student() {
    cout<<this->name<<endl;
    if(pFirst==this) {
        pFirst=pNext;
        return;
    }
    for(Student *pS=pFirst;pS;pS=pS->pNext) {
        if(pS->pNext==this) {
            pS->pNext=pNext;
            return;
        }
    }
}

Student *fn() {
    Student *pS=new Student((char*)"Jenny");
    Student sb((char*)"Jone");
    return pS;
}

int main() {
    cout << "----------------begain------------------" << endl;
    Student sa((char*)"Jamsa");
    Student *sb=fn();
    Student sc((char*)"Tracey");
    delete sb;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
Jone
Jenny
----------------end------------------
Tracey
Jamsa

 * 
 */
