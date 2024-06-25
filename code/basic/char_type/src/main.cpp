/***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

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

/**
 * @expected output:
----------------begain------------------
The ASCII code for M is 77
Add one to the character code :
The ASCII code for N is 78
Displaying char ch using cout.put(ch):N!
done
----------------end------------------
 */
