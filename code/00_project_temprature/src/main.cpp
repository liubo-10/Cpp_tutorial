/***********************************************************
 * @file name: main.cpp
 * @author: liubo
 * @date: 2024.04.18
 * @describe: 
 *   观察者模式
 *   行为型模式：主要关注的是对象之间的通信
 *   观察者-监听者模式（发布-订阅模式）设计模式：主要关注的是对象的一对多的关系，也就是多个对象都依赖一个对象，当该对象的状态发生改变是，其他对象都能够接收到相应通知。
 *   比如有一组数据，生成一个数据对象，通过这一组数据可以生成曲线图（对象1）/柱状图（对象2）/圆饼图（对象3），当数据对象发生改变时，对象1、对象2、对象3应该及时的收到相应的通知！
 * 
 **********************************************************/
#include<iostream>

#include"Observer.h"
#include"Subject.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "----------------begain------------------" << endl;
    
    Subject subject;
    Observer* p1 = new Observer1();
    Observer* p2 = new Observer2();
    Observer* p3 = new Observer3();
    
    subject.addObserver(p1, 1);
    subject.addObserver(p1, 2);
    subject.addObserver(p2, 2);
    subject.addObserver(p3, 1);
    subject.addObserver(p3, 3);
    
    int msgid = 0;
    for (;;)
    {
        cout << "输入消息id:";
        cin >> msgid;
        if (msgid == -1)
            break;
        subject.dispatch(msgid);
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
输入消息id:1
Observer1 recv 1 msg!
Observer3 recv 1 msg!
输入消息id:2
Observer1 recv 2 msg!
Observer2 recv 2 msg!
输入消息id:3
Observer3 recv 3 msg!
输入消息id:4
输入消息id:5
输入消息id:6
输入消息id:-1
----------------end------------------

 */
