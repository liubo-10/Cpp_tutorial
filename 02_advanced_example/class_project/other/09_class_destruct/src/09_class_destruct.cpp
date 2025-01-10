/***********************************************************
 * @file name: 09_class_destruct.cpp
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

class Student {
  public:
    Student(char *pName=(char*)"no name") {
        cout<<"create one student\n";
        strncpy(name,pName,40);
        name[39]='\0';
        noOfStudents++;
        cout<<noOfStudents<<endl;
    }
    ~Student() {
        cout<<"destruct one student\n";
        noOfStudents--;
        cout<<noOfStudents<<endl;
    }
    static int number() {
        return noOfStudents;
    }
  protected:
    static int noOfStudents;
    char name[40];
};

int Student::noOfStudents=0;

void fn() {
    Student s1;
    Student s2;
    cout<<Student::number()<<endl;
}

int main() {
    cout << "----------------begain------------------" << endl;

    Student wang;
    cout<<"into fn\n";
    fn();
    cout<<"outof fn\n";
    cout<<Student::number()<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
----------------begain------------------
create one student
1
into fn
create one student
2
create one student
3
3
destruct one student
2
destruct one student
1
outof fn
1
----------------end------------------
destruct one student
0

 */
