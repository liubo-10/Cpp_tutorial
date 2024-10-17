/***********************************************************
 * @file name: 23_friend_class.cpp
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
    Student(char *s1,char *s2) {
        strcpy(name,s1);
        strcpy(num,s2);
    }
  private:
    friend class Score;
    char name[10],num[10];
};
class Score {
  public:
    Score(unsigned int i1,unsigned int i2,unsigned int i3):
    mat(i1),phy(i2),eng(i3)
    {}
    
    void show() {
        cout<<"Mathematics:"<<mat
        <<"\nPhysics:"<<phy
        <<"\nEnglish:"<<eng<<endl;
    }
    void show(Student&);
  private:
    unsigned int mat,phy,eng;
};
void Score::show(Student& st) {
    cout<<"Name:"<<st.name<<"\n";
    show();
}

int main() {
    cout << "----------------begain------------------" << endl;

    Student wang((char*)"wang",(char*)"1990");
    Score ss(72,82,92);
    ss.show(wang);

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
Name:wang
Mathematics:72
Physics:82
English:92
----------------end------------------
 * 
 */
