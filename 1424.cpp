/*
 * @Author: Hata
 * @Date: 2020-05-20 16:10:06
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 16:23:47
 * @FilePath: \LeetCode\1424.cpp
 * @Description: https://leetcode-cn.com/problems/diagonal-traverse-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &nums)
    {
        std::map<int, std::vector<int>> tree;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums[i].size(); ++j)
            {
                tree[i + j].push_back(nums[i][j]);
            }
        }
        std::vector<int> res;
        std::for_each(tree.begin(), tree.end(), [&res](const auto &p) {
            res.insert(res.end(), p.second.rbegin(), p.second.rend());
        });
        return res;
    }
};