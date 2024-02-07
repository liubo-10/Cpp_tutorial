/***********************************************************
 * @file name: 27_operator_++.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Increase {
  public:
    Increase(int x):value(x){}
    Increase & operator ++();
    Increase operator ++(int);
    
    void display() {
        cout<<"the value is:"<<value<<endl;
    }
  private:
    int value;

};
Increase & Increase::operator ++() { //前++
    value++;
    return *this;
}

Increase Increase::operator ++(int) {
    Increase temp(* this);
    value++;
    return temp;
}
int main() {
    cout << "----------------begain------------------" << endl;

    Increase n(20);
    n.display();
    cout<< "++n ";
    (++n).display();
    n.display();

    cout<< "n++ ";
    (n++).display();
    n.display();

    ++(++n);
    cout<< "++(++n) ";
    n.display();
    (n++)++;
    cout<< "(n++)++ ";
    n.display();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
the value is:20
++n the value is:21
the value is:21
n++ the value is:21
the value is:22
++(++n) the value is:24
(n++)++ the value is:25
----------------end------------------

 */
