/***********************************************************
 * @file name: 04_structure_function_reload02.cpp
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

class test {
  private:
    int num;
    float f1;
  public:
    test(int n);	
    test(int n,float f);
};
inline test::test(int n) {
    cout<<"Initializing\t"<<n<<endl;
    num=n;	
}
test::test(int n,float f) {
    cout<<"Initializing\t"<<n<<","<<f<<endl;
    num=n;
    f1=f;	
}



int main() {
    cout << "----------------begain------------------" << endl;
    test array1[3]={1,2,3};
    test array2[]={test(2,3.5),test(4)};
    test array3[]={test(5.5,6.5),test(7,8.5)}; 
    test array4[]={test(5.5,6.5),7.5,8.5}; 

    test array01=1;
    test array02(2);
    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}





/**
 * @expected output:

Initializing    1
Initializing    2
Initializing    3

Initializing    2,3.5
Initializing    4

Initializing    5,6.5
Initializing    7,8.5

Initializing    5,6.5
Initializing    7
Initializing    8

 * 
 */
