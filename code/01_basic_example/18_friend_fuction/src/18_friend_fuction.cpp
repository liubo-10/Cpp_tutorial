/***********************************************************
 * @file name: 18_friend_fuction.cpp
 * @author: liubo
 * @date: 2024.02.05
 * @describe: 
 * 就是为了不受类的封装性的约束 ，好让我们可以 访问类私有数据成员。语法上使用friend关键字。
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
    char name[10],num[10];
    friend void show(Student& st) { // 将全局函数声明为友元
        cout<<"Name:"<<st.name<<endl<<"Number:"<<st.num<<endl;
    }
};
class Score {
  public:
    Score(unsigned int i1,unsigned int i2,unsigned int i3):
    mat(i1),phy(i2),eng(i3)
    {}
  private:
    unsigned int mat,phy,eng;
    friend void show_all(Student&, Score *); // 将全局函数声明为友元
};
void show_all(Student& st,Score *sc) {
    show(st);
    cout << "Mathematics:" << sc->mat << endl;
    cout << "Physics:" << sc->phy << endl;
    cout << "English:" << sc->eng << endl;
}

int main() {
    cout << "----------------begain------------------" << endl;

    Student wang((char*)"Wang",(char*)"9901");
    Score ss(72,82,92);
    show_all(wang, &ss);

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
Name:Wang
Number:9901
Mathematics:72
Physics:82
English:92
----------------end------------------
 * 
 */
