/*
 * @Author: Hata
 * @Date: 2020-05-11 19:27:06
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 19:40:48
 * @FilePath: \LeetCode\10-09.cpp
 * @Description: https://leetcode-cn.com/problems/sorted-matrix-search-lcci/
 */
#include <bits/stdc++.h>

class Solution
{
    struct Comp
    {
        bool operator()(const std::vector<int> &s, int i) const { return s.back() < i; }
        bool operator()(int i, const std::vector<int> &s) const { return i < s.front(); }
    } comp;

public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix.front().empty())
            return false;
        auto big_pair = std::equal_range(matrix.begin(), matrix.end(), target, this->comp);

        for (auto it = big_pair.first; it != big_pair.second; ++it)
            if (std::binary_search(it->begin(), it->end(), target))
                return true;

        return false;
    }
};