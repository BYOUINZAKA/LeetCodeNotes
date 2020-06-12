/*
 * @Author: Hata
 * @Date: 2020-06-09 08:22:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-09 08:42:34
 * @FilePath: \LeetCode\508.cpp
 * @Description: https://leetcode-cn.com/problems/most-frequent-subtree-sum/
 */
#include "leetcode.h"

class Solution
{
public:
    std::vector<int> findFrequentTreeSum(TreeNode *root)
    {
        if (!root)
            return {};
        std::unordered_map<int, int> table;
        std::map<int, std::vector<int>> resTable;

        dfs(root, table);
        for (auto &&pair : table)
        {
            resTable[pair.second].push_back(pair.first);
        }
        return resTable.crbegin()->second;
    }

    int dfs(TreeNode *node, std::unordered_map<int, int> &table)
    {
        if (node == nullptr)
            return 0;
        int sum = dfs(node->left, table) + dfs(node->right, table) + node->val;
        ++table[sum];
        return sum;
    }
};