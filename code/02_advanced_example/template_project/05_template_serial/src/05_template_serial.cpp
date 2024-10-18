/***********************************************************
 * @file name: 05_template_serial.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

template< typename  T>
class tem {
  public :
    tem(int);
    ~tem() {
        delete[] data;
    }
    T& operator[](int i) {
        return data[i];
    }
  private:
    T *data;
    int size;
};

template<class T>
tem<T>::tem(int n) {
    data=new T[n];
    size=n;
}

int main() {
    cout << "----------------begain------------------" << endl;

    tem<int> x(5);
    int i;
    for(i=0;i<5;i++) {
        x[i]=i;
    }
    for(i=0;i<5;i++) {
        cout<<x[i]<<' ';
    }
    cout<<"\n";

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
0 1 2 3 4 
----------------end------------------

 */
