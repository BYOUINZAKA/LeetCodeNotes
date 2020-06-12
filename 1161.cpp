/*
 * @Author: Hata
 * @Date: 2020-06-10 18:46:04
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-11 16:14:53
 * @FilePath: \LeetCode\1161.cpp
 * @Description: https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/
 */
#include "leetcode.h"

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int maxLevel = 1, curLevel = 1, maxSum = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            int curSum = 0;
            while (s != 0)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                curSum += front->val;
                s--;
            }
            if (curSum > maxSum)
            {
                maxSum = curSum;
                maxLevel = curLevel;
            }
            curLevel++;
        }
        return maxLevel;
    }
};