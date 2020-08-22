/*
 * @Author: Hata
 * @Date: 2020-08-21 12:19:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-21 12:52:07
 * @FilePath: \LeetCode\375.cpp
 * @Description: https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                
                int min_cost = std::numeric_limits<int>::max();
                int j = i + len - 1;

                for (int p = i + (len - 1) / 2; p < i + len - 1; ++p) {
                    int cost = p + std::max(dp[i][p - 1], dp[p + 1][j]);
                    min_cost = std::min(cost, min_cost);
                }
                
                dp[i][j] = min_cost;
            }
        }
        return dp[1][n];
    }
};
