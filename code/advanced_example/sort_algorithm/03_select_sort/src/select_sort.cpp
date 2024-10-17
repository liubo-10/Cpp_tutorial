/***********************************************************
 * @file name: select_sort.cpp
 * @author: liubo
 * @date: 2024.01.25
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

void SelectSort(int* pData,int Count) {
    int iTemp;
    int iPos;
    for(int i=0;i<Count-1;i++) {
        iTemp = pData[i];
        iPos = i;
        for(int j=i+1;j<Count;j++) {
            if(pData[j]<iTemp) {
                iTemp = pData[j];
                iPos = j;
            }
        }
        pData[iPos] = pData[i];
        pData[i] = iTemp;
    }
}

int main(){
    cout << "----------------begain------------------" << endl;

    int data[] = {10,9,8,7,6,5,4};
    SelectSort(data,7);
    for (int i=0;i<7;i++) {
        cout<<data[i]<<" ";
    }
    cout<<"\n";

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}


/*
3.选择法：

现在我们终于可以看到一点希望：选择法，这种方法提高了一点性能（某些情况下）
这种方法类似我们人为的排序习惯：从数据中选择最小的同第一个值交换，在从省下的部分中选择最小的与第二个交换，这样往复下去。

该排序法的图示如下;  i=0时：  iTemp = pData[0]=10；iPos = i=0；
​    j=1 ;
​    pData[j]<iTemp ---> pData[1]=9<10;
​    iTemp=pData[1]=9;
​    ipos=j=1;
​    j++=2
​    j=2;
​    pData[j]<iTemp----> pData[2]=8<9;
​    iTemp=pData[2]=8;
​    ipos=j=2;
​    j++=3
​    . . .
​    j=6;
​    pData[j]<iTemp----> pData[6]=4<5;
​    iTemp=pData[6]=4;
​    ipos=j=6;
​    j++=7; 
​    pData[6]=Pdata[0];
​    pData[0]=4;   
​
before_compare	one turn	two turn	three turn
10		4		4		4
9		9		5		5
8		8		8		6
7		7		7		7
6		6		6		8
5		5		9		9
4		10		10		10

由上面可以看到选择排序法并没有在一开始就交换数据，
而是用第一个数据去和所有的数据比较，如果第一个数据小于第二个数据，
那么，先把第二个数据放到一个临时变量里面，同时记录这个较小的数据在待排序的集合中的位置。
再用该集合中的下一个数据和我们之前放在临时变量中的数据比较。
也就是我们目前认为最小的数据比较，如果比我们之前选出来的数据小，那么再替换该变量。
如果比这个数据大，则继续用下一个数据来比较。知道所有的数据都比较完为止。
到这时，临时变量里面访的就是最小的数据了。我们把这个数据和第一个数据做对换。
此时，最小的元素排到了第一位。倒序(最糟情况)

第一轮：10,9,8,7->(iTemp=9)10,9,8,7->(iTemp=8)10,9,8,7->(iTemp=7)7,9,8,10(交换1次)
第二轮：7,9,8,10->7,9,8,10(iTemp=8)->(iTemp=8)7,8,9,10(交换1次)
第一轮：7,8,9,10->(iTemp=9)7,8,9,10(交换0次)
循环次数：6次
交换次数：2次


其他：
第一轮：8,10,7,9->(iTemp=8)8,10,7,9->(iTemp=7)8,10,7,9->(iTemp=7)7,10,8,9(交换1次)
第二轮：7,10,8,9->(iTemp=8)7,10,8,9->(iTemp=8)7,8,10,9(交换1次)
第一轮：7,8,10,9->(iTemp=9)7,8,9,10(交换1次)
循环次数：6次
交换次数：3次
遗憾的是算法需要的循环次数依然是1/2*(n-1)*n。所以算法复杂度为O(n*n)。
我们来看他的交换。由于每次外层循环只产生一次交换（只有一个最小值）。所以f(n)<=n
所以我们有f(n)=O(n)。所以，在数据较乱的时候，可以减少一定的交换次数。

*/


