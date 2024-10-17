/***********************************************************
 * @file name: 07_class_nest.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;


class Student {
  public:
    Student() {
        cout<<"constructing student.\n";
        semesHours=100;
        gpa=3.5;
    }
    ~Student() {
        cout<<"destructing student.\n";
    }
  protected:
    int semesHours;
    float gpa;
};

class Teacher {
  public:
    Teacher() {
        cout<<"constructing teacher.\n";
    }
    ~Teacher() {
        cout<<"destructing teacher.\n";
    }
};


class Tutorpair {
  public:
    Tutorpair() {
        cout<<"constructing tutorpair.\n";
        nomeeting=0;
    }
    ~Tutorpair() {
        cout<<"destructing tutorpair.\n";
    }
  protected:
    Student student;
    Teacher teacher;
    int nomeeting;
};


int main() {
    cout << "----------------begain------------------" << endl;

    Tutorpair tp;
    cout<<"back main.\n";

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
constructing student.
constructing teacher.
constructing tutorpair.
back main.
----------------end------------------
destructing tutorpair.
destructing teacher.
destructing student.

 */
