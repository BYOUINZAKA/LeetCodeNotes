/*
 * @Author: Hata
 * @Date: 2020-07-31 13:54:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-31 14:03:54
 * @FilePath: \LeetCode\1325.cpp
 * @Description: https://leetcode-cn.com/problems/delete-leaves-with-a-given-value/
 */

#include "leetcode.h"

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return root;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (isLeafNode(root) && root->val == target) root = nullptr;
        
        return root;
    }

private:
    bool isLeafNode(TreeNode* root) { return root->left == nullptr && root->right == nullptr; }
};