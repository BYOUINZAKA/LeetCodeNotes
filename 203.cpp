/*
 * @Author: Hata
 * @Date: 2020-08-13 11:00:06
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-13 11:19:06
 * @FilePath: \LeetCode\203.cpp
 * @Description: https://leetcode-cn.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        if (head->val == val) {
            ListNode* old = head;
            head = head->next;
            delete old;
        }
        return head;
    }
};