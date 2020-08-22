/*
 * @Author: Hata
 * @Date: 2020-08-22 10:23:57
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-22 10:31:04
 * @FilePath: \LeetCode\142.cpp
 * @Description: https://leetcode-cn.com/problems/linked-list-cycle-ii/
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while (head) {
            if (!std::less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};