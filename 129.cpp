/*
 * @Author: Hata
 * @Date: 2020-06-04 07:12:36
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 07:23:44
 * @FilePath: \LeetCode\129.cpp
 * @Description: https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 */
#include "leetcode.h"

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int value)
    {
        if (node == nullptr)
            return 0;
        value = value * 10 + node->val;
        return (node->left || node->right) ? dfs(node->left, value) + dfs(node->right, value)
                                           : value;
    }
};