/*
 * @Author: Hata
 * @Date: 2020-05-25 15:55:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-25 16:03:07
 * @FilePath: \LeetCode\179.cpp
 * @Description: https://leetcode-cn.com/problems/largest-number/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string largestNumber(std::vector<int> &nums)
    {
        if (std::all_of(nums.begin(), nums.end(), [](const auto &i) { return i == 0; }))
        {
            return "0";
        }
        std::vector<std::string> strs(nums.size());
        std::transform(nums.begin(), nums.end(), strs.begin(), [](const auto &i) { return std::to_string(i); });
        std::sort(strs.begin(), strs.end(), [](const auto &a, const auto &b) {
            return a + b > b + a;
        });
        return std::accumulate(strs.begin(), strs.end(), std::string{});
    }
};