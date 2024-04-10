/***********************************************************
 * @file name: 03_STL_stack.cpp
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

const int SIZE=10;

class Cstack {
  public:
    void init() {
        position=0;	
    }
    char push(char ch);
    char pop();
  private:
    char stk[SIZE];
    int position;
};
char Cstack::push(char ch) {
    if(position==SIZE) {
        cout<<"栈满"<<endl;
        return 0;
    }
    stk[position++]=ch;
    return ch;
}
char Cstack::pop() {
    if(position==0) {
        cout<<"\n栈空"<<endl;
        return 0;
    }
    return stk[--position];
}

int main() {
    cout << "----------------begain------------------" << endl;

    Cstack s;
    s.init();
    char ch;
    cout<<"please input some characters:"<<endl; 
    cin>>ch;
    while(ch!='#'&&s.push(ch)) {
        cin>>ch;
    }
    cout<<endl;
    cout<<"now output the data:"<<endl;
    while(ch=s.pop()) {
        cout<<ch;
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
 * 
 * 
 */
