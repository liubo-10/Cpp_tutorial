/***********************************************************
 * @file name: 24_person_class.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

class Person {
  public:
    Person(char *name,int age,char sex) {
        strcpy(m_strName,name);
        m_nSex=(sex=='m'?0:1);
        m_nAge=age;
    }
    void ShowMe() {
        cout<<"姓名："<<m_strName<<endl;
        cout<<"性别："<<(m_nSex==0?"男":"女")<<endl;
        cout<<"年龄："<<m_nAge<<endl;
    }
  protected:
    char m_strName[10];
    int m_nSex;
    int m_nAge;
};

class Teacher:public Person {
  public:
    Teacher(char *name,int age,char sex,char *dept,int salary):
    Person(name,age,sex) {
        strcpy(m_strDept,dept);
        m_fSalary=salary;
    }
    void ShowMe() {
        Person::ShowMe();
        cout<<"工作单位："<<m_strDept<<endl;
        cout<<"月    薪："<<m_fSalary<<endl;
    }
  private:
    char m_strDept[20];
    int m_fSalary;
};

class Student:public Person {
    char m_strID[12];
    char m_strClass[12];
  public:
    Student(char *name,int age,char sex,char *ID,char *Class):
    Person(name,age,sex) {
        strcpy(m_strID,ID);
        strcpy(m_strClass,Class);
    }
    void ShowMe() {
        Person::ShowMe();
        cout<<"学号："<<m_strID<<endl;
        cout<<"班级："<<m_strClass<<"\n";
    }
};
int main() {
    cout << "----------------begain------------------" << endl;

    Teacher teacher((char*)"刘馨",38,'m',(char*)"计算机系",3800);
    Student student((char*)"王丽",20,'v',(char*)"03214521",(char*)"计算机03班");
    teacher.ShowMe();
    cout<<"-------------------------"<<endl;
    student.ShowMe();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
姓名：刘馨
性别：男
年龄：38
工作单位：计算机系
月    薪：3800
-------------------------
姓名：王丽
性别：女
年龄：20
学号：03214521
班级：计算机03班
----------------end------------------

 */
