/*
 * @Author: Hata
 * @Date: 2020-05-22 14:28:59
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-22 14:33:23
 * @FilePath: \LeetCode\1200.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-absolute-difference/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr)
    {
        std::vector<std::vector<int>> res;
        std::sort(arr.begin(), arr.end());
        int min = std::numeric_limits<int>::max();
        for (auto it = arr.cbegin() + 1; it != arr.cend(); ++it)
            min = std::min(min, *it - *(it - 1));
        for (auto it = arr.cbegin() + 1; it != arr.cend(); ++it)
            if (*it - *(it - 1) == min)
                res.push_back({*(it - 1), *it});
        return res;
    }
};