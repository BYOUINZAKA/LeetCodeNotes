/*
 * @Author: Hata
 * @Date: 2020-05-31 23:04:14
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-01 00:43:06
 * @FilePath: \LeetCode\1367.cpp
 * @Description: https://leetcode-cn.com/problems/linked-list-in-binary-tree/
 */
#include "leetcode.h"

class Solution
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode *node, TreeNode *root)
    {
        if (node == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (node->val == root->val)
            return dfs(node->next, root->left) || dfs(node->next, root->right);
        else
            return false;
    }
};