// mentu.cpp : 定义控制台应用程序的入口点。

/*1.耶稣有13个门徒，其中有一个就是出卖耶稣的叛徒，
请用排除法找出这位叛徒：13人围坐一圈，从第一个开始报号：1，2，3，1，2，3……，
凡是报到“3”就退出圈子，最后留在圈内的人就是出卖耶稣的叛徒，请找出它原来的序号*/

/*
 * 使用循环链表实现要求
 */

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<process.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;


int main(void)
{
    node *head = new node;       //创建头节点
    head->next = head;           //循环链表
    node *p = head;  
    p->data = 1;              //给第一个节点赋值
 
    int i;
    for(i=12; i>0; i--)
    {
        node *p = new node;      //分配新节点
        p->data = i+1;            //从13减一开始赋值
        p->next = head->next;    //指向域指向下一个节点
        head->next = p;           //插到头节点后
    }
   
    int count=0;             
    node *q, *pq=NULL;              
    p = head;                 
 
    while(1)
    {
        count++;           //计数加一
        q = p;             //保存前一节点方便删除
        p=p->next;         //沿链表移动指针
       
        if(count==2)      //计数到3
        {
            if(pq == p)       //链表只剩最后一个节点
            {
                cout<<p->data<<endl;
                return 0;
            }
            /*删除节点*/
            q->next = p->next;
            delete[] p;
           
            count=0;   //计数清0
            pq = p = q->next; //p指向下一节点,pq标志
        }
    }
	cout<<"Hello World"<<endl;
    system("pause");
    return 0;
}