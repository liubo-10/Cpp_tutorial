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
    using std::endle;
    {
        cout << "String an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lenttuce Prey");
        StringBad sports("Spinach Leave Bowl for Dollars");
        cout << "headline1:" << headline1 << endle;
        cout << "headline2:" << headline2 << endle;
        cout << "sports:" << sports << endle;
        callme1(headline1);
        cout << "headline1:" << headline1 << endle;

        callme1(headline2);
        cout << "headline2:" << headline2 << endle;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor:" << sailor << endle;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot" << knot << endle;
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

void callme2(StringBad& rsb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << rsb << "\"\n";
}

/***********************************************************
 * end of file
 **********************************************************/
