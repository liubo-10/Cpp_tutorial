/***********************************************************
 * @file name: insert_sort2.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * @expected output:
 * 
 **********************************************************/
#include<iostream>
#include<unistd.h>

using std::cin;
using std::cout;
using std::endl;

void coutstream(int a[],int n) {
    for(int i=0;i!=n;i++)
    cout<<a[i]<<" ";
}

void insertsort(int a[],int n) {
    int temp;
    for(int i=1;i<n;i++) {
        int j=i;
        temp=a[i]; //先把a[i]位置的数据存起来
        while(j>0&&temp<a[j-1]) {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
}


int main(){
    cout << "----------------begain------------------" << endl;
    int a[5]={1,6,4,8,4};
    insertsort(a,5);//插入排序
    coutstream(a,5);//
    return 0;

    cout << "----------------end------------------" << endl;
    //pause();
    return EXIT_SUCCESS;
}

/*
5.插入法2：

*/