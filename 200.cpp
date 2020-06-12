/*
 * @Author: Hata
 * @Date: 2020-06-12 18:06:38
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-12 19:07:02
 * @FilePath: \LeetCode\200.cpp
 * @Description: https://leetcode-cn.com/problems/number-of-islands/
 */
#include <bits/stdc++.h>

class Solution
{
    const constexpr static int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    std::tuple<int, int> flag = {0, 0};

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int res = 0;
        while (!grid.empty())
        {
            auto &&[i, j] = find(grid);
            if (i == -1)
                break;
            else
                dfs(grid, i, j);
            ++res;
        }
        return res;
    }

    void dfs(std::vector<std::vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid.front().size();
        ++grid[i][j];
        for (auto &&d : dir)
        {
            int di = i + d[0], dj = j + d[1];
            if (di >= 0 && di < m && dj >= 0 && dj < n && grid[di][dj] == '1')
                dfs(grid, i + d[0], j + d[1]);
        }
    }

    std::tuple<int, int> find(const std::vector<std::vector<char>> &grid, char val = '1')
    {
        int m = grid.size(), n = grid.front().size();
        auto &&[iflag, jflag] = flag;
        for (int i = iflag; i < m; ++i)
        {
            for (int j = i == iflag ? jflag : 0; j < n; ++j)
            {
                if (grid[i][j] == val)
                {
                    flag = std::make_tuple(i, j);
                    return flag;
                }
            }
        }
        return std::make_tuple(-1, -1);
    }
};

int main()
{
    int a = 5;
    std::tuple<int, int> tuple1{a, 1};
    auto tuple2 = std::make_tuple(a, 1);
}