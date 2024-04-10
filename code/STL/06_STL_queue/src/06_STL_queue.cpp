/***********************************************************
 * @file name: 06_STL_queue.cpp
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

class queue {
    /*默认私有*/
    int q[100];
    int sloc,rloc;
  public:
    queue();
    void qput(int i);
    int qget();
};
queue::queue() {
    sloc=rloc=0;
    cout<<"queue initialized"<<endl;
}
void queue::qput(int i) {
    if(sloc==100) {
        cout<<"queue is full"<<endl;
        return;	
    }
    sloc++;
    q[sloc]=i;
}
int queue::qget() {
    if(rloc==sloc) {
        cout<<"queue is empty"<<endl;
        return 0;	
    }
    rloc++;
    return q[rloc];
}

int main() {
    cout << "----------------begain------------------" << endl;

    queue a,b;
    a.qput(10);
    b.qput(20);
    a.qput(20);
    b.qput(19);
    cout<<a.qget()<<" ";
    cout<<b.qget()<<"\n";
    cout<<a.qget()<<" "; 
    cout<<b.qget()<<"\n";

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
 * 
 * 
 */
