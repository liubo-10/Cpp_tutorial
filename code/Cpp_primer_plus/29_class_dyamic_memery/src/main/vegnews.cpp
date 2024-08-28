/*****************************************************************************
 * | @file    : vegnews.cpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-08-26
 * --------------
 * | @brief   : 程序清单12.3 vegnews.cpp
 *              using new and delete with classes
 ******************************************************************************/

#include <iostream>  // string.h for some
#include "string_bad.h"

using std::cout;

void callme1(StringBad&);  // pass by reference
void callme2(StringBad);   // pass by value

int main()
{
    using std::endl;
    {
        cout << "String an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lenttuce Prey");
        StringBad sports("Spinach Leave Bowl for Dollars");
        cout << "headline1:" << headline1 << endl;
        cout << "headline2:" << headline2 << endl;
        cout << "sports:" << sports << endl;
        callme1(headline1);
        cout << "headline1:" << headline1 << endl;

        callme1(headline2);
        cout << "headline2:" << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;  // 复制构造函数
        cout << "sailor:" << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot" << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End od main()\n";
    return 0;
}

void callme1(StringBad& rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad rsb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << rsb << "\"\n";
}

/***********************************************************
 * end of file
 **********************************************************/
