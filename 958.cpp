/*
 * @Author: Hata
 * @Date: 2020-08-17 13:50:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-17 15:04:11
 * @FilePath: \LeetCode\958.cpp
 * @Description: https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/
 */
#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool flag = false;
        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* tmp = que.front();
            que.pop();
            if (tmp == nullptr) flag = true;
            if (flag && tmp) return false;
            if (tmp) {
                que.push(tmp->left);
                que.push(tmp->right);
            }
        }
        return true;
    }
};