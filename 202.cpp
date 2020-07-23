/*
 * @Author: Hata
 * @Date: 2020-07-10 19:22:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-10 19:38:14
 * @FilePath: \LeetCode\202.cpp
 * @Description: https://leetcode-cn.com/problems/happy-number/
 */
#include <bits/stdc++.h>

class Solution
{
    std::unordered_set<int> table;

public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;

        int res = 0;
        for (; n > 0; n /= 10)
            res += std::pow(n % 10, 2);

        auto &&[it, success] = table.insert(res);

        return success ? isHappy(res) : false;
    }
};