/*
 * @Author: Hata
 * @Date: 2020-06-04 06:16:15
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 07:11:04
 * @FilePath: \LeetCode\988.cpp
 * @Description: https://leetcode-cn.com/problems/smallest-string-starting-from-leaf/
 */
#include "leetcode.h"

class Solution
{
    std::string res{"z"};

public:
    std::string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, "");
        return res;
    }

    void dfs(TreeNode *node, std::string &&s)
    {
        if (node == nullptr)
            return;
        s.push_back(node->val + 'a');
        if (node->left == nullptr && node->right == nullptr)
        {
            std::reverse(s.begin(), s.end());
            if (s < res)
                res = s;
        }
        dfs(node->left, std::string{s});
        dfs(node->right, std::string{s});
    }
};