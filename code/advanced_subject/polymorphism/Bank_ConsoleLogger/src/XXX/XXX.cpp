/*****************************************************************************
 * | @file    : XXX.c
 * | @author  : liubo
 * | @version : V1.0.0     |V1.0.1     |V1.0.2
 * | @date    : 2024-01-05 |2024-08-22 |2024-09-01
 * --------------
 * | @brief   : CPP template
 ******************************************************************************/
#include "XXX.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*****************************************************************************
 * | @fn     : XXXX
 * | @param  : - cmd 命令码
 * |           - dataPtr 发送的数据
 * |           - Len 发送的数据长度
 * | @return :
 * --------------
 * | @brief  : 发送请求到智能电池
 * |           通过串口2发送
 ******************************************************************************/
int main()
{
    cout << "----------------begain------------------" << endl;

    char ch = 'M';  // assign ASCII code for M to ch
    int i = ch;     // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code :" << endl;
    ch = ch + 1;  // charge characrer code in ch
    i = ch;       // save new character code in i
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch):";
    cout.put(ch);

    // using the cout.put() to display a char constant
    cout.put('!');

    cout << endl << "done" << endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}















/***********************************************************
 * end of file
 **********************************************************/
