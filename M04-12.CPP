/*
 * @Author: Hata
 * @Date: 2020-07-15 17:17:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-15 17:32:47
 * @FilePath: \LeetCode\M04-12.CPP
 * @Description: https://leetcode-cn.com/problems/paths-with-sum-lcci/
 */
#include "leetcode.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return dfs(sum, root, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(const int sum, TreeNode* node, int curr_sum) {
        if (node == nullptr) return 0;
        curr_sum += node->val;
        return (curr_sum == sum) + dfs(sum, node->left, curr_sum) + dfs(sum, node->right, curr_sum);
    }
};