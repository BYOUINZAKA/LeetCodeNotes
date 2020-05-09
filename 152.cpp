/*
 * @Author: Hata
 * @Date: 2020-05-06 12:19:53
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 12:45:13
 * @FilePath: \LeetCode\152.cpp
 * @Description: 乘积最大子数组
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int res = std::numeric_limits<int>::min();
        int max = 1, min = 1;
        for (auto &&i : nums)
        {
            if (i < 0)
                std::swap(max, min);
            max = std::max(max * i, i);
            min = std::min(min * i, i);
            res = std::max(max, res);
        }
        return res;
    }
};