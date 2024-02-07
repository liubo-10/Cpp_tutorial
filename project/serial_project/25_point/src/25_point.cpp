/***********************************************************
 * @file name: 25_point.cpp
 * @author: liubo
 * @date: 2024.02.07
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout;
using std::endl;

class Point {
    int x,y;
  public:
    Point() {}
    Point(int l,int w) {
        x=l;
        y=w;
    }
    void disp() {
        cout<<"面积："<<x*y<<endl;
    }
    Point operator ,(Point r) {
        Point temp;
        temp.x=r.x;
        temp.y=r.y;
        return temp;
    }
    Point operator +(Point r) {
        Point temp;
        temp.x=r.x+x;
        temp.y=r.y+y;
        return temp;
    }
};
int main() {
    cout << "----------------begain------------------" << endl;

    Point r1(1,2),r2(3,4),r3(5,6);
    r1.disp();
    r2.disp();
    r3.disp();
    r1=(r1,r2+r3,r3);
    r1.disp();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
面积：2
面积：12
面积：30
面积：30
----------------end------------------

 */
