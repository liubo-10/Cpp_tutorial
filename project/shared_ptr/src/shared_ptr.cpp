/*

shared_ptr.cpp


*/
#include<iostream>
#include<memory> 

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main() {
    shared_ptr<int> p1 = make_shared<int>(); // make_shared 创建空对象，
	*p1 = 10;
	cout << "p1 = " << *p1 << endl; // 输出10

	// 打印引用个数：1
	cout << "p1 count = " << p1.use_count() << endl;
	
	// 第2个 shared_ptr 对象指向同一个指针
	std::shared_ptr<int> p2(p1);
	
	// 输出2
	cout << "p2 count = " << p2.use_count() << endl;
	cout << "p1 count = " << p1.use_count() << endl;
    
    cout<<"Hello World"<<endl;
    return 0;
}

