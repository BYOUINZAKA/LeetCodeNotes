/*
 * @Author: Hata
 * @Date: 2020-05-05 18:26:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-05 18:47:28
 * @FilePath: \LeetCode\652.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        std::vector<TreeNode *> res;
        std::unordered_map<std::string, bool> map;
        dfs(root, res, map);
        return res;
    }

    std::string dfs(TreeNode *root, std::vector<TreeNode *> &res, std::unordered_map<std::string, bool> &map)
    {
        if (root == nullptr)
            return std::string{};
        std::string str = std::to_string(root->val) + "," + dfs(root->left, res, map) + "," + dfs(root->right, res, map);
        std::cout << str << std::endl;

        if (map[str] == true)
        {
            res.push_back(root);
        }
        map[str]++;
        return str;
    }
};