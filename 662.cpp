/*
 * @Author: Hata
 * @Date: 2020-05-11 15:50:48
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 16:25:39
 * @FilePath: \LeetCode\662.cpp
 * @Description: https://leetcode-cn.com/problems/maximum-width-of-binary-tree/
 */
#include "leetcode.h"

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        std::queue<std::pair<TreeNode *, unsigned long long>> queue;
        typename decltype(queue)::value_type::second_type max = 1;

        queue.emplace(root, 1);
        while (!queue.empty())
        {
            int size = queue.size();
            max = std::max(max, queue.back().second - queue.front().second + 1);
            for (int i = 0; i < size; ++i)
            {
                auto node = queue.front().first;
                auto pos = queue.front().second;
                queue.pop();

                if (node->left)
                    queue.emplace(node->left, 2 * pos);
                if (node->right)
                    queue.emplace(node->right, 2 * pos + 1);
            }
        }
        return max;
    }
};