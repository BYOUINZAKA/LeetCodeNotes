/*
 * @Author: Hata
 * @Date: 2020-05-09 13:10:47
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-09 13:59:26
 * @FilePath: \LeetCode\19.cpp
 * @Description: 
 */

#include "leetcode.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
            return nullptr;
        ListNode *ptr = head, *slow = head;
        int i;
        for (i = 0; ptr != nullptr; ++i)
        {
            if (i > n)
                slow = slow->next;
            ptr = ptr->next;
        }
        if (i == n)
            return head->next;
        else
            slow->next = slow->next->next;
        return head;
    }
};