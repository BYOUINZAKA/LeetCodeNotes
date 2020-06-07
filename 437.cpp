/*
 * @Author: Hata
 * @Date: 2020-06-06 19:33:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-06 21:12:54
 * @FilePath: \LeetCode\437.cpp
 * @Description: https://leetcode-cn.com/problems/path-sum-iii/
 */
#include "leetcode.h"

class Solution
{
    int pathCount = 0;

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        backtrack(sum, root, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return pathCount;
    }

    void backtrack(const int target, TreeNode *node, int current)
    {
        if (node == nullptr)
            return;

        current += node->val;
        if (current == target)
            ++pathCount;

        backtrack(target, node->left, current);
        backtrack(target, node->right, current);
    }
};