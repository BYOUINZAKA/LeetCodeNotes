/*
 * @Author: Hata
 * @Date: 2020-05-07 14:20:38
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-30 19:34:14
 * @FilePath: \LeetCode\leetcode.h
 * @Description: 
 */

#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};