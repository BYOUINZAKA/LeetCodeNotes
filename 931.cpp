/*
 * @Author: Hata
 * @Date: 2020-05-17 11:02:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-17 11:20:49
 * @FilePath: \LeetCode\931.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-falling-path-sum/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int minFallingPathSum(const std::vector<std::vector<int>> &A)
    {
        std::vector<std::vector<int>> dp(A.size(), std::vector<int>(A.front().size(), 0));
        dp.back() = A.back();
        for (int i = dp.size() - 2; i >= 0; --i)
        {
            auto size = A[i].size();
            dp[i][0] = A[i][0] + std::min(dp[i + 1][0], dp[i + 1][1]);
            for (int j = 1; j < size - 1; ++j)
            {
                dp[i][j] = A[i][j] + std::min(std::min(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]);
            }
            dp[i][size - 1] = A[i][size - 1] + std::min(dp[i + 1][size - 1], dp[i + 1][size - 2]);
        }
        return *std::min_element(dp.front().begin(), dp.front().end());
    }
};