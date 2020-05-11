/*
 * @Author: Hata
 * @Date: 2020-05-11 10:17:04
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 10:18:54
 * @FilePath: \LeetCode\32-1.cpp
 * @Description: 
 */


#include "leetcode.h"

class Solution
{
public:
    std::vector<int> levelOrder(TreeNode *root)
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
            while (count > 0)
            {
                auto node = queue.front();
                queue.pop();
                --count;
                result.push_back(node->val);
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
        }
        return result;
    }
};