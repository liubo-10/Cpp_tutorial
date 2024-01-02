/*

number_count.cpp


*/
#include<iostream>
//#include<process.h>// windows引入头文件system("pause") 

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int currVal=0,val=0; //currVal当前保留的值,val新输入的值。
    if(cin>>currVal) {
        int cnt=1;
        while (cin>>val) {
            if(val==currVal) {
                ++cnt; 
            } else {
                cout<<currVal<<" occurs "<<cnt<<" times"<<endl;
                currVal=val;
                cnt=1;
            }
        }
        std::cout<<currVal<<" occurs "<<cnt<<"times"<<endl;
    }
    cout<<"Hollow world"<<endl;
    system("pause"); // 暂停往下执行 按下任意键继续
    // std::cout << "Press Enter to continue..."; 
    std::cin.get(); // 等待用户按下 Enter 键 
    return 0;
}

