#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

#include "function1.h"
#include "function2.h"

int main(void)
{
	list<int> mylist;

    for(inti=0;i<5;i++)
    {
        mylist.push_back(i);
    }
    
    for (auto iter = mylist.begin(); iter != mylist.end(); iter++) 
    {
        std::cout << " " << *iter << std::end;
    }

    std::cout << " " << mylist.size() << std::end;
    mylist.erase(mylist.begin());
    std::cout << " " << mylist.size() << std::end;
    
    for (auto iter = mylist.begin(); iter != mylist.end(); iter++) 
    {
        std::cout << " " << *iter << std::end;
    }
    
    return 0;
}
