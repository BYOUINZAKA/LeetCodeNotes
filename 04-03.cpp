/*
 * @Author: Hata
 * @Date: 2020-06-04 07:28:52
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 07:43:42
 * @FilePath: \LeetCode\04-03.cpp
 * @Description: https://leetcode-cn.com/problems/list-of-depth-lcci/
 */
#include "leetcode.h"

class Solution
{
public:
    std::vector<ListNode *> listOfDepth(TreeNode *tree)
    {
        std::vector<ListNode *> res;
        std::queue<TreeNode *> queue;
        if (tree)
            queue.push(tree);
        while (!queue.empty())
        {
            auto size = queue.size();
            ListNode *ptr;
            for (int i = 0; i < size; ++i)
            {
                auto node = queue.front();
                queue.pop();
                if (i == 0)
                {
                    res.emplace_back(new ListNode{node->val});
                    ptr = res.back();
                }
                else
                {
                    ptr->next = new ListNode{node->val};
                    ptr = ptr->next;
                }
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return res;
    }
};