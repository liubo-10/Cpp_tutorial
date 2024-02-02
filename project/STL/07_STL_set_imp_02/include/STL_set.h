/***********************************************************
 * @file name: STL_set.h
 * @author: liubo
 * @date: 2024.02.02
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const int maxCard=16;
enum ErrCode{noErr,overflow};
enum Bool{False,True};

class Set {
  public:
    Set(int sz=maxCard) {
        card=0;
        size=sz;
        elems=new int[size];
    }
    ~Set() {
        delete []elems;
    }

    Bool Member(int);
    ErrCode AddElem(int);
    void RmvElem(int);
    void Copy(Set *);
    Bool Equal(Set *);
    void Print();
    void Intersect(Set *,Set *);
    ErrCode Union(Set *,Set *);

  private:
    int size;
    int *elems;
    int card;
};

