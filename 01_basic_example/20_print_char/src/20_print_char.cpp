/***********************************************************
 * @file name: 20_print_char.cpp
 * @author: liubo
 * @date: 2024.02.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "----------------begain------------------" << endl;
    for(int i=1; i<=10; i++) {
        for(int j=1; j<=10-i; j++) {
            cout<<" ";
        }
        for(char ch='A'; ch<'A'+2*i-1; ch++) {
            cout<<ch;
        }
        cout<<"\n";
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
         A
        ABC
       ABCDE
      ABCDEFG
     ABCDEFGHI
    ABCDEFGHIJK
   ABCDEFGHIJKLM
  ABCDEFGHIJKLMNO
 ABCDEFGHIJKLMNOPQ
ABCDEFGHIJKLMNOPQRS
----------------end------------------
 * 
 */
