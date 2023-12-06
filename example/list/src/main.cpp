#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

#include "function1.h"
#include "function2.h"

int main(void)
{
	std::list<int> mylist;

    for(int i=0; i<5; i++)
    {
        mylist.push_back(i);
    }
    
    std::cout << "mylist:";
    for (auto iter = mylist.begin(); iter != mylist.end(); iter++) 
    {
        std::cout << " " << *iter;
    }
    std::cout<<std::endl;
    std::cout << "mylist.size():" << mylist.size() << std::endl;
    std::cout<<std::endl;

    // 调用erase()
    mylist.erase(mylist.begin());

    std::cout << "mylist.begin() erase:" << *mylist.begin() <<std::endl;

    std::cout << "mylist erase:";
    for (auto iter = mylist.begin(); iter != mylist.end(); iter++) 
    {
        std::cout << " " << *iter;
    }
    std::cout<<std::endl;
    std::cout << "mylist.size() erase:" << mylist.size() << std::endl;

    return 0;
}
