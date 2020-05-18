/*
 * @Author: Hata
 * @Date: 2020-05-18 20:10:26
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-18 20:18:00
 * @FilePath: \LeetCode\63.cpp
 * @Description: https://leetcode-cn.com/problems/unique-paths-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid.front().size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp.back().back();
    }
};