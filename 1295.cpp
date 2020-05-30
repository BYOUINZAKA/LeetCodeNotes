/*
 * @Author: Hata
 * @Date: 2020-05-25 19:47:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-25 19:55:35
 * @FilePath: \LeetCode\1295.cpp
 * @Description: https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int findNumbers(std::vector<int> &nums)
    {
        int res = 0;
        std::for_each(
            nums.begin(),
            nums.end(),
            [&res](const auto &s) {
                if ((std::to_string(s).length() | 0) == 0)
                    ++res;
            });
        return res;
    }
};