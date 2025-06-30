/*****************************************************************************
 * | @file    : .cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-06-09
 * ---------------------------------------
 * | @brief   : main template

 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string>
#include <unistd.h>  // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s == "") {
            return 0;
        }
        else if (s.size() == 1) {
            return 1;
        }

        int head, tail, length;
        tail = 0;
        for (head = 1; head < s.size(); head++) {
            for (int j = tail; j < head; j++) {
                if (s[j] == s[head]) {
                    tail = j + 1;
                    break;
                }
            }

            if (length < head + 1 - tail) {
                length = head + 1 - tail;
            }
        }

        return length;
    }
};

/*****************************************************************************
 * end of file
 ******************************************************************************/
