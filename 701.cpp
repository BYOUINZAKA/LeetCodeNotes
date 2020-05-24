/*
 * @Author: Hata
 * @Date: 2020-05-24 13:33:18
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 13:42:48
 * @FilePath: \LeetCode\701.cpp
 * @Description: https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
 */
#include "leetcode.h"

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            root = new TreeNode(val);
        else if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};