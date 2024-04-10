/***********************************************************
 * @file name: 19_friend_fuction_02.cpp
 * @author: liubo
 * @date: 2024.02.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string.h>
#define strmax 32

using std::cin;
using std::cout;
using std::endl;

class myclass {
  public:
    myclass(int vx,int vy,char *str);
    ~myclass() { // 超出作用域自动执行
        cout << "----------------~myclass------------------" << endl;
        delete []string;
    }
    friend int sum(myclass& c1); // 将全局函数声明为友元
    friend int strlength(myclass& c1);
    friend void print(myclass& c1);
  private:
    int x,y;
    char *string;
};
myclass::myclass(int vx,int vy,char *str) {
    x=vx;
    y=vy;
    string = new char[strmax];
    strcpy(string,str);
}

int sum(myclass& c1) { // 函数参数为类，使用引用 ，否则会产生释放问题
    return c1.x+c1.y;
}

int strlength(myclass& c1) {
    return strlen(c1.string);
}

void print(myclass& c1) {
    cout << "----------------print------------------" << endl;
    cout<<"x="<<c1.x<<endl<<"y="<<c1.y<<endl;
    cout<<"string:"<<c1.string<<endl;
}

int main() {
    cout << "----------------begain------------------" << endl;

    myclass c1(10,10,(char*)"my myclass object!");
    cout<<"the sum is:"<<sum(c1)<<endl;
    cout<<"the string is:"<<strlength(c1)<<endl;
    print(c1);

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
the sum is:20
the string is:18
----------------print------------------
x=10
y=10
string:my myclass object!
----------------end------------------
----------------~myclass------------------
 * 
 */
