/*
 * @Author: Hata
 * @Date: 2020-07-15 17:41:21
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-15 18:21:59
 * @FilePath: \LeetCode\222.cpp
 * @Description: https://leetcode-cn.com/problems/count-complete-tree-nodes/
 */
#include "leetcode.h"

class Solution {
    int count = 0;
    bool found = false;
    std::optional<int> max_deep;

public:
    int countNodes(TreeNode* root) {
        rdfs(root, 0);
        return std::pow(2, max_deep.value_or(0)) - (found ? count : 0) - 1;
    }

    void rdfs(TreeNode* node, const int level) {
        if (node == nullptr) {
            if (max_deep.has_value() && level > max_deep)
                found = true;
            else
                ++count;
            max_deep = level;
        } else {
            if (!found) rdfs(node->right, level + 1);
            if (!found) rdfs(node->left, level + 1);
        }
    }
};