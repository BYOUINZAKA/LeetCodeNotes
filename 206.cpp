/*
 * @Author: Hata
 * @Date: 2020-05-22 14:12:41
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-22 14:26:21
 * @FilePath: \LeetCode\206.cpp
 * @Description: https://leetcode-cn.com/problems/reverse-linked-list/
 */
#include "leetcode.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = head, *node = head->next, *next = node->next;
        pre->next = nullptr;
        node->next = pre;
        while (next)
        {
            pre = node;
            node = next;
            next = next->next;
            if (node)
                node->next = pre;
        }
        return node;
    }
};