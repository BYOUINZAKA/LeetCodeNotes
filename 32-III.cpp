/*
 * @Author: Hata
 * @Date: 2020-06-02 17:33:03
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-02 18:08:00
 * @FilePath: \LeetCode\32-III.cpp
 * @Description: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 */
#include "leetcode.h"

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> queue;
        std::vector<std::vector<int>> res;
        if (root)
            queue.push(root);
        while (!queue.empty())
        {
            auto size = queue.size();
            std::vector<int> temp;
            for (int i = 0; i < size; ++i)
            {
                auto node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if((int)res.size() & 1)
                std::reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};