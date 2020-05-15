/*
 * @Author: Hata
 * @Date: 2020-05-15 10:53:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-15 11:02:54
 * @FilePath: \LeetCode\337.cpp
 * @Description: https://leetcode-cn.com/problems/house-robber-iii/
 */
#include "leetcode.h"

class Solution
{
public:
    int rob(TreeNode *root)
    {
        auto res = cal(root);
        return std::max(res.front(), res.back());
    }

    std::vector<int> cal(TreeNode *node)
    {
        if (node == nullptr)
            return {0, 0};

        auto left = cal(node->left);
        auto right = cal(node->right);

        return std::vector<int>{
            std::max(left.front(), left.back()) + std::max(right.front(), right.back()),
            node->val + left.front() + right.front()};
    }
};