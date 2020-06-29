/*
 * @Author: Hata
 * @Date: 2020-06-29 16:11:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-29 16:28:56
 * @FilePath: \LeetCode\offer47.cpp
 * @Description: https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    template <class V>
    int maxValue(V &&grid)
    {
        auto dp{std::forward<V>(grid)};
        int n = dp.size(), m = dp.front().size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                dp[i][j] += std::max(i >= 1 ? dp[i - 1][j] : 0, j >= 1 ? dp[i][j - 1] : 0);
            }
        }
        return dp.back().back();
    }
};