/*
 * @Author: Hata
 * @Date: 2020-06-10 18:15:12
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-10 18:42:18
 * @FilePath: \LeetCode\987.cpp
 * @Description: https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/
 */
#include "leetcode.h"

class Solution
{
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        std::vector<std::tuple<int, int, int>> nodes;
        dfs(root, 0, 0, nodes);
        std::sort(nodes.begin(), nodes.end(), [](auto &&lhs, auto &&rhs) {
            auto &&[x1, y1, v1] = lhs;
            auto &&[x2, y2, v2] = rhs;
            return x1 != x2 ? x1 < x2 : (y1 != y2 ? y1 > y2 : v1 < v2);
        });
        int level = std::numeric_limits<int>::max();
        for (auto &&p : nodes)
        {
            auto &&[x, y, val] = p;
            if (x != level)
            {
                res.emplace_back();
                level = x;
            }
            res.back().push_back(val);
        }
        return res;
    }

    void dfs(TreeNode *node, int x, int y, std::vector<std::tuple<int, int, int>> &nodes)
    {
        if (node == nullptr)
            return;
        nodes.emplace_back(x, y, node->val);
        dfs(node->left, x - 1, y - 1, nodes);
        dfs(node->right, x + 1, y - 1, nodes);
    }
};