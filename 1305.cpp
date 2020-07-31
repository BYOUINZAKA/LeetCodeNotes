/*
 * @Author: Hata
 * @Date: 2020-07-29 16:41:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-29 16:54:13
 * @FilePath: \LeetCode\1305.cpp
 * @Description: https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
 */

#include "leetcode.h"

class Solution {
public:
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> left, right, res;

        getNodes(root1, left);
        getNodes(root2, right);

        std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(res));

        return res;
    }

    void getNodes(TreeNode* node, std::vector<int>& out) {
        if (node) {
            getNodes(node->left, out);
            out.push_back(node->val);
            getNodes(node->right, out);
        }
    }
};