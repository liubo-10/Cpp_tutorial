/***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: small arrays of integers
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "----------------begain------------------" << endl;

    int yams[3]; // creates array with three elements
    yams[0] = 7; // assign value to first element
    yams[1] = 8;
    yams[2] = 8;

    int yamcosts[3] = {20, 30, 5}; //create, initialize array

    /**
     * NOTE: If your C++ compiler or translator can't initialize
     * this array, use static int yamcosts[3] instead of
     * int yamcosts[3] */
    
    cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams coat ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "The tatol yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0] << " byte.\n";

    cout << "----------------end------------------" << endl;

    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
Total yams = 23
The package with 8 yams coat 30 cents per yam.
The tatol yam expense is 420 cents.

Size of yams array = 12 bytes.
Size of one element = 4 byte.
----------------end------------------

 */

