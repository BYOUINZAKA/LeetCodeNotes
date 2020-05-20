/*
 * @Author: Hata
 * @Date: 2020-05-20 20:01:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 20:13:26
 * @FilePath: \LeetCode\226.cpp
 * @Description: https://leetcode-cn.com/problems/invert-binary-tree/
 */
#include "leetcode.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        std::function<TreeNode *(TreeNode *)> invert;
        invert = [&invert](TreeNode *node) {
            if (node == nullptr)
                return node;
            std::swap(node->left, node->right);
            invert(node->left);
            invert(node->right);
            return node;
        };
        return invert(root);
    }
};