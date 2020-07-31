'''
@Author: Hata
@Date: 2020-07-30 09:27:42
@LastEditors: Hata
@LastEditTime: 2020-07-30 09:29:33
@FilePath: \LeetCode\M02-04.py
@Description: https://leetcode-cn.com/problems/partition-list-lcci/
'''

# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        p, q = head, head
        while q:
            if q.val < x:
                q.val, p.val = p.val, q.val
                p = p.next
            q = q.next
        return head