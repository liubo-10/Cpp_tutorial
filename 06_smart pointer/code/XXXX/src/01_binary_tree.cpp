/***********************************************************
 * @file name: 01_binary_tree.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<stdlib.h>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
class BinaryTree;
template<typename T>
class Node {
  public:
    Node() {
        lchild=NULL;
        rchild=NULL;
    }
    Node(T data, Node<T> *left=NULL, Node<T> *right=NULL) {
        info=data;
        lchild=left;
        rchild=right;
    }
    friend class BinaryTree<T>;
  private:
    Node<T> *lchild,*rchild;
    T info;
};

template<typename T>
class BinaryTree {
  public:
    BinaryTree() {
        root=NULL;
    }
    ~BinaryTree() {
        Destory(root);
    }
    void Creat(T *data,int n);
    void InOrder() {
        InOrder(root);
    }
    void Remove(const T &data) {
        Remove(data,root,root);
    }
  private:
    Node<T> *root;
    void InOrder(Node<T> *Current);
    void Insert(const T &data,Node<T> * &b);
    void Remove(const T &data,Node<T> * &a,Node<T> * &b);
    void Destory(Node<T> *Current);
};

template<typename T>
void BinaryTree<T>::Destory(Node<T> *Current) {
    if(Current!=NULL) {
        Destory(Current->lchild);
        Destory(Current->rchild);
        delete Current;
    }
}

template<typename T>
void BinaryTree<T>::Insert(const T &data, Node<T> * &b) {
    if(b==NULL) {
        b=new Node<T>(data);
        if(b==NULL) {
            cout<<"空间不足"<<endl;
            exit(1);
        }
    } else if(data<b->info) {
        Insert(data,b->lchild);
    } else {
        Insert(data,b->rchild);
    }
}

template<typename T>
void BinaryTree<T>::Creat(T *data,int n) {
    for(int i=0;i<n;i++) {
        Insert(data[i],root);
    }
}

template<typename T>
void BinaryTree<T>::InOrder(Node<T> *Current) {
    if(Current!=NULL) {
        InOrder(Current->lchild);
        cout<<Current->info<<"  ";
        InOrder(Current->rchild);
    }
}

template<typename T>
void BinaryTree<T>::Remove(const T &data, Node<T> * &a, Node<T> * &b) {
    Node<T> *temp1, *temp2;
    if(b!=NULL) {
        if(data < b->info) {
            Remove(data,b,b->lchild);
        } else if(data > b->info) {
            Remove(data,b,b->rchild);
        } else if(b->lchild!=NULL && b->rchild!=NULL) {
            temp2=b;
            temp1=b->rchild;
            if(temp1->lchild!=NULL) {
                while(temp1->lchild!=NULL) {
                    temp2=temp1;
                    temp1=temp1->lchild;
                }
                temp2->lchild=temp1->rchild;
            } else {
                temp2->rchild=temp1->rchild;
            }
            b->info=temp1->info;
            delete temp1;
        } else {
            temp1=b;
            if(b->rchild!=NULL) {
                temp1=b->rchild;
                b->info=temp1->info;
                b->rchild=temp1->rchild;
                b->lchild=temp1->lchild;
            } else if(b->lchild!=NULL) {
                temp1=b->lchild;
                b->info=temp1->info;
                b->rchild=temp1->rchild;
                b->lchild=temp1->lchild;
            } else if(b==root) {
                root=NULL;
            } else if(a->rchild==temp1){
                a->rchild=NULL;
            } else {
                a->lchild=NULL;
            }
            delete temp1;
        }
    }
}

int main() {
    cout << "----------------begain------------------" << endl;

    const int n=15;
    int i,a[n]={10,5,15,8,3,18,13,12,14,16,20,1,4,6,9};
    BinaryTree<int> btree;
    btree.Creat(a,n);
    cout<<"输入数据："<<endl;
    for(i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"中序："<<endl;
    btree.InOrder();
    btree.Remove(a[13]);
    cout<<endl<<"Remove(a[13]) 中序："<<endl;
    btree.InOrder();
    btree.Remove(a[3]);
    cout<<endl<<"Remove(a[3]) 中序："<<endl;
    btree.InOrder();
    btree.Remove(a[9]);
    cout<<endl<<"Remove(a[9]) 中序："<<endl;
    btree.InOrder();
    btree.Remove(a[2]);
    cout<<endl<<"Remove(a[2]) 中序："<<endl;
    btree.InOrder();
    btree.Remove(a[0]);
    cout<<endl<<"Remove(a[0]) 中序："<<endl;
    btree.InOrder();
    int a1[1]={10};
    BinaryTree<int> btree1;
    btree1.Creat(a1,1);
    cout<<"输入数据："<<"\t"<<a1[0]<<"\t";
    cout<<endl<<"中序："<<"\t";
    btree1.InOrder();
    btree1.Remove(a[0]);
    cout<<endl<<"Remove(a[0]) 中序："<<endl;
    btree1.InOrder();

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:


 */
