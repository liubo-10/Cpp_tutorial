/***********************************************************
 * @file name: Subject.cpp
 * @author: liubo
 * @date: 2024.04.18
 * @describe: 
 *   Subject（主题)主题有更改，应该及时通知相应的观察者，去处理相应的事件
 * 
 **********************************************************/
#include<unordered_map>
#include<list>

using std::unordered_map;
using std::list;

//主题类
class Subject
{
  public:
    void addObserver(Observer* obser, int msgid)
    {
        _subMap[msgid].push_back(obser);
        /*
        auto it = _subMap.find(msgid);
        if (it != _subMap.end())
        {
            it->second.push_back(obser);
        }
        else
        {
            list<Observer*> lis;
            lis.push_back(obser);
            _subMap.insert({ msgid,lis });
        }
        */
    }
    //主题检测发生改变，通知相应的观察者对象处理事件
    void dispatch(int msgid)
    {
        auto it = _subMap.find(msgid);
        if (it != _subMap.end())
        {
            for (Observer* pObser : it->second)
            {
                pObser->handle(msgid);
            }
        }
    }
  private:
    unordered_map<int, list<Observer*>> _subMap;
};

