/* *********************************************************
 * file name: 02_pointer_cout.cpp
 * author: liubo
 * date: 2024.01.24
 * describe: 
 *   cout打印整形数组a,相当于打印整型地址,输出首地址
 *   cout打印字符数组c,相当于打印字符型地址,输出字符串
 * 
 * Expected output:
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    cout << "----------------begain------------------" << endl;

    cout << "\n----------------数组地址打印 测试------------------" << endl;

    int  a[5]={1,2,3,5};
    int* pa;
    pa = a;

    cout << a << endl;        // 输出首地址
    cout << a + 1 << endl;    // 输出次地址 首地址 + 4
    cout << pa << endl;       // 输出首地址
    cout << *a << endl;       // 1 
    cout << *(a + 1) << endl; // 2
    cout << *pa << endl;      // 1


    cout << "\n----------------字符地址打印 测试------------------" << endl;
    char  c[5] = {'a','b','c','d','e'};
    char* pc;
    pc = c;

    cout << c << endl;      //输出字符串 abcde
    cout << c + 1 << endl;  //输出字符串 bcde
    cout << pc << endl;     //输出字符串 abcde
    cout << pc + 1 << endl; //输出字符串 bcde

    cout << (int*)c << endl;        // 输出首地址
    cout << (int*)pc << endl;       // 输出首地址
    cout << (int*)(c + 1) << endl;  // 输出次地址 首地址 + 1
    cout << (int*)(pc + 1) << endl; // 输出次地址 首地址 + 1

    cout << *(int*)c << endl;        // 输出
    cout << *(int*)pc << endl;       // 输出

    char c2[5] = {1,1,0,0,0};
    cout << *(int*)c2 << endl;        // 输出 257 即二进制 100000001(整型占用四个字节32位)

    cout<<"Hello World"<<endl;
    return 0;
}

