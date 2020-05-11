/*
 * @Author: Hata
 * @Date: 2020-05-11 19:48:23
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 20:15:11
 * @FilePath: \LeetCode\1416.cpp
 * @Description: https://leetcode-cn.com/problems/restore-the-array/
 */
#include <bits/stdc++.h>

class Solution
{
    constexpr static const int MOD = 1e9 + 7;

public:
    int numberOfArrays(const std::string &s, int k)
    {
        std::vector<int> dp(s.length() + 1, 0);
        dp.front() = 1;

        for (int i = 1; i < dp.size(); ++i)
        {
            long long num = 0, fold = 1;
            for (int j = i - 1; j >= 0 && i - j <= 10; --j, fold *= 10)
            {
                num += (s[j] - '0') * fold;
                if (num > k)
                    break;
                if (s[j] != '0')
                {
                    dp[i] += dp[j];
                    dp[i] %= MOD;
                }
            }
        }

        return dp.back();
    }
};