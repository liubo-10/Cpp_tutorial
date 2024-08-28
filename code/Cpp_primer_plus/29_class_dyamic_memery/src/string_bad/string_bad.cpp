/*****************************************************************************
 * | @file    : string_bad.cpp
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-08-26
 * --------------
 * | @brief   : 程序清单12.2 strngbad.cpp
 *              StringBad class methods
 ******************************************************************************/

#include <cstring>  // string.h for some
#include "string_bad.h"

using std::cin;
using std::cout;
using std::endl;

// initializing static class member
// 静态类成员是单独存储的，而不是对象的组成部分
int StringBad::num_strings = 0;

// class methods
// construct StringBad from C string
StringBad::StringBad(const char* s)
{
    len = std::strlen(s);  // set size

    str = new char[len + 1];  // allot storage
    std::strcpy(str, s);      // initialize pointer

    num_strings++;                                                   // set object count
    cout << num_strings << ": \" " << str << "\" object created\n";  // For Your Information
}

StringBad::StringBad()  // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");  // default string
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";  // FYI
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object delete, ";  // FYI
    --num_strings;                                // required
    cout << num_strings << "left\n";              // FYI
    delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
    os << st.str;
    return os;
}

/***********************************************************
 * end of file
 **********************************************************/
