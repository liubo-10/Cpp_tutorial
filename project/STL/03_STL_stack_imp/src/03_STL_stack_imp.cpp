/***********************************************************
 * @file name: 03_STL_stack_imp.cpp
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

class stack;
class node {
  public:
    node(int d,node *n) {
        data=d;
        prev=n;
    }
    friend class stack;
  private:
    int data;
    node *prev;
};

class stack {
  public:
    stack() {
        top = nullptr;
    }
    void push(int i);
    int pop();
  private:
    node *top;
};

void stack::push(int i) {
    node *n = new node(i,top);
    top=n;
}

int stack::pop() {
    node *t=top;
    if(top) {
        top=top->prev;
        int c=t->data;
        delete t;
        return c;
    }
    return 0;
}

int main() {
    cout << "----------------begain------------------" << endl;
    cout << "input ten number:" << endl;
    int c;
    stack s;
    for(int i=0;i<10;i++) {
        cin>>c;
        s.push(c);
    }
    for(int i=0;i<10;i++) {
        cout<<s.pop()<<" ";
    }
    cout<<"\n";

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
input ten number:
34
56
79
234
456
7
97
2
4
678
678 4 2 97 7 456 234 79 56 34 
----------------end------------------
 * 
 */
