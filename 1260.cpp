/*
 * @Author: Hata
 * @Date: 2020-08-13 10:52:45
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-13 10:59:42
 * @FilePath: \LeetCode\1260.cpp
 * @Description: https://leetcode-cn.com/problems/shift-2d-grid/
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(const std::vector<std::vector<int>>& grid, int k) {
        const int k_n = grid.size(), k_m = grid.front().size();
        auto new_grid = grid;

        for (int i = 0; i < k_n; i++) {
            for (int j = 0; j < k_m; j++) {
                const int new_j = (j + k) % k_m;
                const int new_i = (i + (j + k) / k_m) % k_n;
                new_grid[new_i][new_j] = grid[i][j];
            }
        }

        return new_grid;
    }
};