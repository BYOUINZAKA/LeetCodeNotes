/*
 * @Author: Hata
 * @Date: 2020-05-25 16:15:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-25 16:21:52
 * @FilePath: \LeetCode\1267.cpp
 * @Description: https://leetcode-cn.com/problems/count-servers-that-communicate/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int countServers(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid.front().size();
        std::vector<int> rows(m), cols(n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1))
                    ++res;
            }
        }
        return res;
    }
};