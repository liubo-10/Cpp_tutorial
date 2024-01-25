/***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * @expected output:
 * 
 **********************************************************/
#include<iostream>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

void ExchangeSort(int* pData,int Count) {
    int iTemp;
    for(int i=0;i<Count-1;i++) {
        for(int j=i+1;j<Count;j++) {
            if(pData[j]<pData[i]) {
                iTemp = pData[i];
                pData[i] = pData[j];
                pData[j] = iTemp;
            }
        }
    }

}

int main(){
    cout << "----------------begain------------------" << endl;
    int data[] = {10,9,8,7,6,5,4};
    ExchangeSort(data,7);
    for (int i=0;i<7;i++) {
        cout<<data[i]<<" ";
    }

    cout<<"\n";
    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}




/*
**2.交换法：**

交换法的程序最清晰简单，每次用当前的元素一一的同其后的元素比较并交换。


before_compare|one_turn|two_turn|three_turn|four_turn|five_turn|six_turn     
10     9     8     7     6      5   4            
9     10     10     10    10      10   10      
8     8     9     9     9      9   9      
7     7     7     8     8      8   8     
6     6     6     6     7      7   7      
5     5     5     5    5     6  6      
4     4     4     4     4      4   5 
从上面的算法来看，基本和冒泡法的效率一样。

倒序(最糟情况)

第一轮：10,9,8,7->9,10,8,7->8,10,9,7->7,10,9,8(交换3次)

第二轮：7,10,9,8->7,9,10,8->7,8,10,9(交换2次)

第一轮：7,8,10,9->7,8,9,10(交换1次)

循环次数：6次

交换次数：6次


其他：

第一轮：8,10,7,9->8,10,7,9->7,10,8,9->7,10,8,9(交换1次)

第二轮：7,10,8,9->7,8,10,9->7,8,10,9(交换1次)

第一轮：7,8,10,9->7,8,9,10(交换1次)

循环次数：6次

交换次数：3次


从运行的表格来看，交换几乎和冒泡一样糟。事实确实如此。
循环次数和冒泡一样也是1/2*(n-1)*n，所以算法的复杂度仍然是O(n*n)。
由于我们无法给出所有的情况，所以只能直接告诉大家他们在交换上面也是一样的糟糕（在某些情况下稍好，在某些情况下稍差）。


*/