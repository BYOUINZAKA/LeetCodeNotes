/*
 * @Author: Hata
 * @Date: 2020-05-14 23:53:46
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-15 00:26:23
 * @FilePath: \LeetCode\1019.cpp
 * @Description: https://leetcode-cn.com/problems/next-greater-node-in-linked-list/
 */
#include "leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    std::vector<int> nextLargerNodes(ListNode *head)
    {
        std::stack<std::pair<int, int>> single_stack;
        std::vector<int> res;
        int i = 0;
        for (auto *p = head; p; p = p->next, ++i)
        {
            res.push_back(0);
            while (!single_stack.empty())
            {
                auto pair = single_stack.top();
                if (p->val <= pair.second)
                    break;
                else
                {
                    res[pair.first] = p->val;
                    single_stack.pop();
                }
            }
            single_stack.emplace(i, p->val);
        }
        return res;
    }
};