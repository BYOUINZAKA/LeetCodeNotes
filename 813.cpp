/*
 * @Author: Hata
 * @Date: 2020-07-04 17:45:22
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-04 23:23:30
 * @FilePath: \LeetCode\813.cpp
 * @Description: https://leetcode-cn.com/problems/largest-sum-of-averages/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    double largestSumOfAverages(std::vector<int> &A, int K)
    {
        const auto N = A.size();
        std::vector<std::vector<double>> dp(K, std::vector<double>(N, 0));
        std::vector<int> sum(N, 0);

        for (int i = 0, s = 0; i < N; ++i)
        {
            sum[i] = (s += A[i]);
            dp[0][i] = s / double(i + 1);
        }

        for (int k = 1; k < K; ++k)
        {
            for (int i = k; i < N; ++i)
            {
                for (int j = i - 1; j >= k - 1; --j)
                {
                    dp[k][i] = std::max(dp[k][i], dp[k - 1][j] + (sum[i] - sum[j]) / double(i - j));
                }
            }
        }

        return dp.back().back();
    }
};