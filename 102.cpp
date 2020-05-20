/*
 * @Author: Hata
 * @Date: 2020-05-20 17:22:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 17:29:23
 * @FilePath: \LeetCode\102.cpp
 * @Description: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 */
#include "leetcode.h"

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        if (root == nullptr)
            return res;
        std::queue<TreeNode *> queue;
        queue.push(root);
        int count = 1;
        while (!queue.empty())
        {
            int add = 0;
            res.emplace_back();
            while (count)
            {
                auto node = queue.front();
                queue.pop();
                --count;
                res.back().push_back(node->val);
                if (node->left)
                {
                    queue.push(node->left);
                    ++add;
                }
                if (node->right)
                {
                    queue.push(node->right);
                    ++add;
                }
            }
            count = add;
        }
        return res;
    }
};