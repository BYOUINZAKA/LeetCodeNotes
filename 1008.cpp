/*
 * @Author: Hata
 * @Date: 2020-06-30 14:25:39
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 14:25:53
 * @FilePath: \LeetCode\1008.cpp
 * @Description: https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/
 */
#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    template <class V>
    TreeNode *bstFromPreorder(V &&preorder)
    {
        TreeNode *root = nullptr;
        for (auto &&node : std::forward<V>(preorder))
            root = build(root, node);
        return root;
    }

    TreeNode *build(TreeNode *root, int num)
    {
        if (root == nullptr)
            return new TreeNode(num);
        if (root->val > num)
            root->left = build(root->left, num);
        else
            root->right = build(root->right, num);
        return root;
    }
};