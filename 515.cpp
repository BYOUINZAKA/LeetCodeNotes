/*
 * @Author: Hata
 * @Date: 2020-05-11 09:54:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 10:17:13
 * @FilePath: \LeetCode\515.cpp
 * @Description: https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 */

#include "leetcode.h"

class Solution
{
public:
    std::vector<int> largestValues(TreeNode *root)
    {
        std::vector<int> result;
        if (!root)
            return result;
        std::queue<TreeNode *> queue;
        queue.push(root);
        int count = 1;
        while (!queue.empty())
        {
            int push = 0;
            int max = std::numeric_limits<int>::min();
            while (count > 0)
            {
                auto node = queue.front();
                queue.pop();
                --count;
                max = std::max(node->val, max);
                if (node->left)
                {
                    queue.push(node->left);
                    ++push;
                }
                if (node->right)
                {
                    queue.push(node->right);
                    ++push;
                }
            }
            count = push;
            result.push_back(max);
        }
        return result;
    }
};