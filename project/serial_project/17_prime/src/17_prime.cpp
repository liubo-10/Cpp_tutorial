/***********************************************************
 * @file name: 17_prime.cpp
 * @author: liubo
 * @date: 2024.02.05
 * @describe: template
 * cmath是c++语言中的标准库头文件。
 * 其中的 “c” 表示其中的函数是来自 C标准库，“math”表示为数学常用库函数。
 * 该头文件主要声明了常用的数学库函数，比如三角函数相关，常用数学运算相关的一些基本函数。
 * 
 **********************************************************/
#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "----------------begain------------------" << endl;
    cout << "please input a number:\n" << endl;
    int m;
    cin >> m;
    double sqrtm = sqrt(m*1.0); // 求平方根
    for(int i=2; i<=sqrtm; i++) {
        if(m%i == 0) {
            cout << m << " is not a prime\n"; // 素数
            return 1;
        }
    }

    cout << m << " is a prime" << endl;
    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}






/**
 * @expected output:
 * 
 * 
 */
