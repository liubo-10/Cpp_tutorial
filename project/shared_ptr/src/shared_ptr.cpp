/*

shared_ptr.cpp


*/
#include<iostream>
#include<memory> // 共享指针必须要包含的头文件

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main() {
    cout << "----------------begain------------------" << endl;

    // 最好使用make_shared创建共享指针
    cout << "\n----------------创建p1------------------" << endl;
    shared_ptr<int> p1 = make_shared<int>(); // make_shared 创建空对象

    *p1 = 10; // 取引用
    cout << "p1 = " << *p1 << endl; // 输出10

    // 打印引用个数：1
    cout << "p1 count = " << p1.use_count() << endl;
    
    cout << "\n----------------创建p2------------------" << endl;
    // 第2个shared_ptr对象指向同一个指针
    std::shared_ptr<int> p2(p1);

    // 打印引用个数：2
    cout << "p1 = " << *p1 << endl; // 输出10
    cout << "p2 = " << *p2 << endl; // 输出10
    cout << "p1 count = " << p1.use_count() << endl; // 输出2
    cout << "p2 count = " << p2.use_count() << endl; // 输出2

    // 比较智能指针，p1等于p2
    if (p1 == p2) {
        std::cout<< "p1 and p2 are pointing to same pointer\n";
    }

    cout << "\n----------------p1 reset()------------------" << endl;
    p1.reset();// 无参数调用reset，无关联指针，引用个数为0
 
    //cout << "p1 = " << *p1 << endl; // 段错误 (核心已转储)
    cout << "p2 = " << *p2 << endl; // 输出10
    cout << "p1 Count = " << p1.use_count() << endl; // 输出0
    cout << "p2 count = " << p2.use_count() << endl; // 输出1

    cout << "\n----------------p1 reset(new)------------------" << endl;
    p1.reset(new int(11));// 带参数调用reset，引用个数为1
    cout << "p1 = " << *p1 << endl; // 输出11
    cout << "p2 = " << *p2 << endl; // 输出10
    cout << "p1 Count = " << p1.use_count() << endl; // 输出1
    cout << "p2 count = " << p2.use_count() << endl; // 输出1

    cout << "\n----------------p1 = nullptr------------------" << endl;
    p1 = nullptr;// 把对象重置为nullptr，引用计数为0
    cout << "p1 Count = " << p1.use_count() << endl; // 输出0

    if (!p1) {
        cout << "p1 is NULL" << endl; // 输出
    }

    cout << "\n----------------end------------------" << endl;
    return 0;
}

