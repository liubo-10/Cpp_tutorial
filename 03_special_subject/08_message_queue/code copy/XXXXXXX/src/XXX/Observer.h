/*****************************************************************************
 * | @file    : Observer.h
 * | @author  : liubo
 * | @version : V1.0.0     |V1.0.1     |
 * | @date    : 2024-04-18 |2024-09-06 |
 * --------------
 * | @brief   : three observers
 *              Observer1、Observer2、Observer3
 ******************************************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Observer
{
  public:
    //处理消息的接口
    virtual void handle(int msgid) = 0;
};

//第一个观察者实例
class Observer1 :public Observer
{
  public:
    void handle(int msgid)
    {
        switch (msgid)
        {
            case 1:
                cout << "Observer1 recv 1 msg!" << endl;
                break;
            case 2:
                cout << "Observer1 recv 2 msg!" << endl;
                break;
            default:
                cout << "Observer1 recv unknow msg!" << endl;
                break;
        }
    }
};

//第二个观察者实例
class Observer2 :public Observer
{
  public:
    void handle(int msgid)
    {
        switch (msgid)
        {
            case 2:
                cout << "Observer2 recv 2 msg!" << endl;
                break;
            default:
                cout << "Observer2 recv unknow msg!" << endl;
                break;
        }
    }
};

//第三个观察者实例
class Observer3 :public Observer
{
  public:
    void handle(int msgid)
    {
        switch (msgid)
        {
            case 1:
                cout << "Observer3 recv 1 msg!" << endl;
                break;
            case 3:
                cout << "Observer3 recv 3 msg!" << endl;
                break;
            default:
                cout << "Observer3 recv unknow msg!" << endl;
                break;
        }
    }
};

/***********************************************************
 * end of file
 **********************************************************/
