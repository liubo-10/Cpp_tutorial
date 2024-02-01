/***********************************************************
 * @file name: 02_structure_function_reload.cpp
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
    test();
    test(int n,float f);
    int getint() {
        return num;
    }
    float getfloat() {
        return f1;
    }
};
test::test() {
    cout<<"Initializing default"<<endl;
    num=0;
    f1=0.0;
}
test::test(int n,float f) {
    cout<<"Initializing"<<n<<","<<f<<endl;
    num=n;
    f1=f;
}

int main() {
    cout << "----------------begain------------------" << endl;
    test x;
    test y(10,21.5); 
    test *px=new test;
    test *py=new test(10,21.5);

    delete px;
    px = nullptr;
    delete py;
    py = nullptr;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
 * 
 * 
 */
