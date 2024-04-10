/***********************************************************
 * @file name: 04_STL_list_ipm.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

template<class T>
class List {
  public:
    List();
    ~List();

    void Add(T&);
    void Remove(T&);
    T *Find(T&);
    void PrintList();

  protected:
    struct Node {
        Node *pNext;
        T *Pt;
    };
    Node *pFirst;
};

template<class T>
List<T>::List() {
    pFirst=0;
}

template<class T>
List<T>::~List() {
    Node *p=pFirst;
    while(!p) {
        pFirst=pFirst->pNext;
        delete p->Pt;
        delete p;
        p=pFirst;
    }
}

template<class T>
void List<T>::Add(T& t) {
    Node *temp=new Node;
    temp->Pt=&t;
    temp->pNext=pFirst;
    pFirst=temp;
}

template<class T>
void List<T>::Remove(T& t) {
    Node *q=0;
    if(*pFirst->Pt==t) {
        q=pFirst;
        pFirst=pFirst->pNext;
    } else {
        for(Node *p=pFirst; p->pNext; p=p->pNext) {
            if(*(p->pNext->Pt)==t) {
                q=p->pNext;
                p->pNext=q->pNext;
                break;
            }
        }
    }
    if(q) {
        delete q->Pt;
        delete q;
    } else {
        cout<<"No such node!"<<endl;
    }
}

template<class T>
T* List<T>::Find(T& t) {
    for(Node *p=pFirst; p; p=p->pNext) {
        if(*(p->Pt)==t) {
            return p->Pt;
        }
    }
    return 0;
}

template<class T>
void List<T>::PrintList() {
    for(Node *p=pFirst; p; p=p->pNext) {
        cout<<*(p->Pt)<<"|";
    }
    cout<<endl;
}

int main() {
    cout << "----------------begain------------------" << endl;

    List<float> floatList;
    for(int i=1;i<7;i++) {
        floatList.Add(* new float((float)(i+0.3)));
    }
    floatList.PrintList();
    float b=(float)3.3;
    float *pa=floatList.Find(b);
    if(pa) {
        floatList.Remove(*pa);
    }
    floatList.Remove(*new float((float)0.3));
    floatList.PrintList();

    // floatList.Remove((float)2.3); // cannot bind non-const lvalue reference of type ‘float&’ to an rvalue of type ‘float’
    // floatList.PrintList();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
----------------begain------------------
6.3|5.3|4.3|3.3|2.3|1.3|
No such node!
6.3|5.3|4.3|2.3|1.3|
----------------end------------------

 */
