/*
 * @Author: Hata
 * @Date: 2020-06-29 16:36:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-29 16:38:21
 * @FilePath: \LeetCode\144.cpp
 * @Description: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */
#include "leetcode.h"

class Solution
{
    std::vector<int> res;

public:
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        DLR(root);
        return res;
    }

    void DLR(TreeNode *node)
    {
        if (node == nullptr)
            return;
        res.push_back(node->val);
        DLR(node->left);
        DLR(node->right);
    }
};