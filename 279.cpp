/*
 * @Author: Hata
 * @Date: 2020-05-19 10:20:54
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-19 10:45:21
 * @FilePath: \LeetCode\279.cpp
 * @Description: https://leetcode-cn.com/problems/perfect-squares/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, std::numeric_limits<int>::max() - 1);
        dp.front() = 0;
        std::vector<int> sqares((int)std::sqrt(n) + 1);
        std::generate(sqares.begin(), sqares.end(), [n = 0]() mutable { return ++n, n * n; });

        for (int i = 1; i <= n; ++i)
        {
            for (auto &&j : sqares)
            {
                if (i < j)
                    break;
                dp[i] = std::min(dp[i], dp[i - j] + 1);
            }
        }

        return dp.back();
    }
};