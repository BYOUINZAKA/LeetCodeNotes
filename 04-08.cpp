/*
 * @Author: Hata
 * @Date: 2020-05-16 17:48:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-16 17:54:12
 * @FilePath: \LeetCode\04-08.cpp
 * @Description: https://leetcode-cn.com/problems/first-common-ancestor-lcci/
 */
#include "leetcode.h"

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (root == p || root == q)
            return root;
        else if (left && right)
            return root;
        else
            return left ? left : right;
    }
};