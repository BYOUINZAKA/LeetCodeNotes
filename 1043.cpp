/*
 * @Author: Hata
 * @Date: 2020-05-06 10:33:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 10:51:47
 * @FilePath: \LeetCode\1043.cpp
 * @Description: 分隔数组以得到最大和
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int maxSumAfterPartitioning(std::vector<int> &A, int K)
    {
        std::size_t size;
        if (size = A.size(), size == 0)
            return 0;
        std::vector<int> dp(size + 1, 0);
        for (int i = 1; i <= size; ++i)
        {
            int max = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k)
            {
                max = std::max(max, A[i - k]);
                dp[i] = std::max(dp[i], dp[i - k] + max * k);
            }
        }
        return dp.back();
    }
};