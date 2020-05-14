/*
 * @Author: Hata
 * @Date: 2020-05-14 12:19:12
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-14 13:02:34
 * @FilePath: \LeetCode\78.cpp
 * @Description: https://leetcode-cn.com/problems/subsets/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using Iter = typename std::vector<int>::iterator;
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        return recurrence(nums.begin(), nums.end());
    }

    std::vector<std::vector<int>> recurrence(Iter first, Iter last)
    {
        if (first == last)
            return {{}};
        auto res = recurrence(first, --last);
        int size = res.size();
        for (int i = 0; i < size; ++i)
        {
            res.push_back(res[i]);
            res.back().push_back(*last);
        }
        return res;
    }
};