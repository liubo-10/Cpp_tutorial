/***********************************************************
 * @file name: 14_class_init.cpp
 * @author: liubo
 * @date: 2024.02.02
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
    char name[10],num[10];
  public:
    Student(char *s1,char *s2) {
        strcpy(name,s1);
        strcpy(num,s2);
    }
    void dsp() {
        cout<<"Name:"<<name<< endl<<"Number:"<<num<< endl;
    }
};

class Score {
    unsigned int mat,phy,eng;
  public:
    Score(unsigned int i1,unsigned int i2,unsigned int i3):
    mat(i1),phy(i2),eng(i3)
    {}
    void show() {
        cout<<"Mathematics:"<<mat<<"\nPhyics:"<<phy<<"\nEnglish:"<<eng<<endl;
    }
};

int main() {
    cout << "----------------begain------------------" << endl;
    Student a((char*)"Wang",(char*)"123456789");
    Score a1(72,82,92);
    a.dsp();
    a1.show();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
 * 
 * 
 */
