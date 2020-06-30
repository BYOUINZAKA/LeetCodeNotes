/*
 * @Author: Hata
 * @Date: 2020-06-30 19:17:48
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 19:20:25
 * @FilePath: \LeetCode\814.cpp
 * @Description: https://leetcode-cn.com/problems/binary-tree-pruning/
 */
#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else
        {
            return root;
        }
    }
};