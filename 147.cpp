/*
 * @Author: Hata
 * @Date: 2020-07-11 12:27:33
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-11 13:12:36
 * @FilePath: \LeetCode\147.cpp
 * @Description: https://leetcode-cn.com/problems/insertion-sort-list/
 */

#include <string_view>
#include <vector>

#include "leetcode.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto ordered = head;

        for (auto ptr = head->next; ptr != nullptr; ptr = ordered->next) {
            if (ptr->val < ordered->val) {
                ordered->next = ptr->next;
                if (ptr->val <= head->val) {
                    ptr->next = head;
                    head = ptr;
                } else {
                    for (auto sub = head; sub != ordered->next; sub = sub->next) {
                        if (ptr->val <= sub->next->val) {
                            ptr->next = sub->next;
                            sub->next = ptr;
                            break;
                        }
                    }
                }
            } else {
                ordered = ordered->next;
            }
        }

        return head;
    }
};