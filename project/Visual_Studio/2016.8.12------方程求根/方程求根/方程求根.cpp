//问题：求一元二次方程式ax2+bx+c=0的根。a,b,c的值在运行时由键盘输入。

#include "stdafx.h"
#include<iostream>  
#include<cmath>      
#include<process.h>
using namespace std;  
int main( )  
{  
             float  a,b,c,x1,x2;  
             cin>>a>>b>>c;  
             if ((b*b-4*a*c)>=0)  
             {  
                 if((b*b-4*a*c)>0)  
                   {  
                            x1=(-b+sqrt(b*b-4*a*c))/(2*a);  
                            x2=(-b-sqrt(b*b-4*a*c))/(2*a);  
                            cout<<"两个不相等的实根分别是：x1="<<x1<<",""x2="<<x2<<endl;  
                   }  
                   else  
                   {  
                            x1=-b/(2*a);  
                            cout<<"两个相等的实根，x1=x2="<<x1<<endl;  
                   }         
             }  
             else  
                   cout<<"方程无实根"<<endl;  
			 system("pause");
             return 0;  
}  