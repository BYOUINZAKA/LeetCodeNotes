/*
 * @Author: Hata
 * @Date: 2020-06-06 21:18:59
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-06 22:44:56
 * @FilePath: \LeetCode\1361.cpp
 * @Description: https://leetcode-cn.com/problems/validate-binary-tree-nodes/
 */
#include <bits/stdc++.h>

class Solution
{
    std::vector<int> leftChild;
    std::vector<int> rightChild;

public:
    bool validateBinaryTreeNodes(int n, std::vector<int> &leftChild, std::vector<int> &rightChild)
    {
        this->leftChild = leftChild;
        this->rightChild = rightChild;
        for (int i = 0; i < n; ++i)
        {
            auto flags = std::vector<unsigned char>(n, 0);
            if (!dfs(flags, i))
                continue;
            if (std::find(flags.cbegin(), flags.cend(), 0) != flags.cend())
                continue;
            return true;
        }
        return false;
    }

    bool dfs(std::vector<unsigned char> &flags, int node)
    {
        if (node == -1)
            return true;
        if (flags[node] != 0)
            return false;
        flags[node] = 1;
        return dfs(flags, leftChild[node]) &&
               dfs(flags, rightChild[node]);
    }
};