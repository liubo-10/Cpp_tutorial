/***********************************************************
 * @file name: 24_real_image.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Complex {
  public:
    Complex(double r=0, double i=0) {
        real = r;
        image = i;
    }
	friend void inputcomplex(Complex &comp);
	friend Complex addcomplex(Complex &c1,Complex &c2);
	friend Complex subcomplex(Complex &c1,Complex &c2);
	friend Complex mulcomplex(Complex &c1,Complex &c2);
	friend void outputcomplex(Complex &comp);
  private:
    double real;
    double image;

};

void inputcomplex(Complex &comp) {
    cin>>comp.real>>comp.image;
}

Complex addcomplex(Complex &c1,Complex &c2) {
    Complex c;
    c.real=c1.real+c2.real;
    c.image=c1.image+c2.image;
    return c;
}

Complex subcomplex(Complex &c1,Complex &c2) {
    Complex c;
    c.real=c1.real-c2.real;
    c.image=c1.image-c2.image;
    return c;
}

Complex mulcomplex(Complex &c1,Complex &c2) {
    Complex c;
    c.real=c1.real*c2.real-c1.image*c2.image;
    c.image=c1.real*c2.image+c1.image*c2.real;
    return c;
}

void outputcomplex(Complex &comp) {
    cout<<"("<<comp.real<<","<<comp.image<<")";
}

int main() {
    cout << "----------------begain------------------" << endl;

    Complex c1,c2,result;
    cout<<"please input the first number's shi and xu:"<<endl;
    inputcomplex(c1);
    cout<<"please input the second number's shi and xu:"<<endl;
    inputcomplex(c2);
    result=addcomplex(c1,c2);
    outputcomplex(c1);
    cout<<"+";
    outputcomplex(c2);
    cout<<"=";
    outputcomplex(result);
    cout<<"\n---------------------------"<<endl;
    result=subcomplex(c1,c2);
    outputcomplex(c1);
    cout<<"-";
    outputcomplex(c2);
    cout<<"=";
    outputcomplex(result);
    cout<<"\n---------------------------"<<endl;
    result=mulcomplex(c1,c2);
    outputcomplex(c1);
    cout<<"*";
    outputcomplex(c2);
    cout<<"=";
    outputcomplex(result);
    cout<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
please input the first number's shi and xu:
1
1
please input the second number's shi and xu:
2
2
(1,1)+(2,2)=(3,3)
---------------------------
(1,1)-(2,2)=(-1,-1)
---------------------------
(1,1)*(2,2)=(0,4)
----------------end------------------
 * 
 */
