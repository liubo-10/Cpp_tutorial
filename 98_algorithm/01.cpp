/*****************************************************************************
 * | @file    : .cpp
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-06-09
 * ---------------------------------------
 * | @brief   : main template
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序
的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

 ******************************************************************************/
#include <iostream>  // 包含输入和输出操作
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件

// #include "XXX.hpp"

using std::cin;
using std::cout;
using std::endl;

// Definition for singly-linked list.
struct ListNode
{
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* add_two_number(ListNode* list1, ListNode* list2)
    {
        int       carry  = 0;
        ListNode* result = new ListNode();
        ListNode* temp   = result;

        while (carry || list1 || list2) {
            int add1 = 0;
            int add2 = 0;

            if (list1) {
                add1  = list1->val;
                list1 = list1->next;
            }

            if (list2) {
                add2  = list2->val;
                list2 = list2->next;
            }

            int res     = add1 + add2 + carry;
            int new_val = res % 10;
            carry       = res / 10;

            temp->next = new ListNode(new_val);
            temp       = temp->next;
        }

        return result->next;
    }

}

/*****************************************************************************
 * end of file
 ******************************************************************************/
