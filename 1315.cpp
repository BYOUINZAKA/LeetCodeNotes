/*
 * @Author: Hata
 * @Date: 2020-05-16 15:35:14
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-16 15:49:39
 * @FilePath: \LeetCode\1315.cpp
 * @Description: https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/
 */
#include "leetcode.h"

class Solution
{
    int sum = 0;

public:
    int sumEvenGrandparent(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if ((root->val & 1) == 0)
        {
            if (root->left)
            {
                sum += (root->left->left) ? root->left->left->val : 0;
                sum += (root->left->right) ? root->left->right->val : 0;
            }
            if (root->right)
            {
                sum += (root->right->left) ? root->right->left->val : 0;
                sum += (root->right->right) ? root->right->right->val : 0;
            }
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};