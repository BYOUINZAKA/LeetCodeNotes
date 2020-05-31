/*
 * @Author: Hata
 * @Date: 2020-05-31 15:26:41
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-31 15:54:51
 * @FilePath: \LeetCode\979.cpp
 * @Description: https://leetcode-cn.com/problems/distribute-coins-in-binary-tree/
 */

#include "leetcode.h"

class Solution
{
public:
    int res = 0;
    int distributeCoins(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int val = dfs(node->left) + dfs(node->right) + node->val - 1;
        this->res += std::abs(val);
        return val;
    }
};