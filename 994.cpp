/*
 * @Author: Hata
 * @Date: 2020-06-04 19:28:24
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 20:09:32
 * @FilePath: \LeetCode\994.cpp
 * @Description: https://leetcode-cn.com/problems/rotting-oranges/
 */
#include <bits/stdc++.h>

class Solution
{
    using Status = std::tuple<int, int, int>;
    int dis[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        std::queue<Status> queue;
        int m = grid.size();
        int n = grid.front().size();
        int times = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2)
                    queue.emplace(i, j, 0);
            }
        }
        while (!queue.empty())
        {
            auto size = queue.size();
            for (int _ = 0; _ < size; ++_)
            {
                auto [i, j, t] = queue.front();
                times = t;
                queue.pop();
                for (auto &&d : dis)
                {
                    int di = i + d[0];
                    int dj = j + d[1];
                    if (di >= 0 && di < m && dj >= 0 && dj < n && grid[di][dj] == 1)
                    {
                        grid[di][dj] = 2;
                        queue.emplace(di, dj, times + 1);
                    }
                }
            }
        }
        for (auto &&i : grid)
            for (auto &&j : i)
                if (j == 1)
                    return -1;
        return times;
    }
};