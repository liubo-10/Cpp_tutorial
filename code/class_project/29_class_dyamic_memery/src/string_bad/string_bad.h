/*****************************************************************************
 * | @file    : string_bad.h
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2024-08-25
 * --------------
 * | @brief   : 程序清单12.1 strngbad.h
 * |            flawed string class definition
 ******************************************************************************/
#ifndef _STRING_BAD_H_
#define _STRING_BAD_H_

#include <iostream>

using std::ostream;

class StringBad
{
   private:
    char* str;               // pointer to string
    int len;                 // lenght of string
    static int num_strings;  // number of objects 类的所有对象共享

   public:
    StringBad(const char* s);  // constructor
    StringBad();               // default constructor
    ~StringBad();              // destructor
    // friend fuction
    friend ostream& operator<<(ostream& os, const StringBad& st);
};

#endif  // #ifndef _STRING_BAD_H_

/***********************************************************
 * end of file
 **********************************************************/
