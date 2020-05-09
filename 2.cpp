/*
 * @Author: Hata
 * @Date: 2020-05-07 14:21:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 14:57:13
 * @FilePath: \LeetCode\2.cpp
 * @Description: 
 */

#include "leetcode.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        int value = l1->val + l2->val;
        int over = value >= 10;
        ListNode *res = new ListNode(over ? value - 10 : value);
        ListNode *head = res;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2)
        {
            value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + over;
            over = value >= 10;
            res->next = new ListNode(over ? value - 10 : value);
            res = res->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (over == 1)
            res->next = new ListNode(1);
        return head;
    }
};