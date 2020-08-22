/*
 * @Author: Hata
 * @Date: 2020-08-16 09:40:59
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-16 09:49:26
 * @FilePath: \LeetCode\733.cpp
 * @Description: https://leetcode-cn.com/problems/flood-fill/
 */
#include <bits/stdc++.h>

class Solution {
    constexpr const static int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc,
                                            int newColor) {
        int base = image[sr][sc];
        if (base != newColor) dfs(image, sr, sc, base, newColor);
        return image;
    }

    void dfs(std::vector<std::vector<int>>& image, int i, int j, int base, int newColor) {
        if (image[i][j] == base) {
            const int N = image.size(), M = image[0].size();

            image[i][j] = newColor;
            for (auto&& d : dir) {
                int di = i + d[0], dj = j + d[1];
                if (di >= 0 && di < N && dj >= 0 && dj < M) {
                    dfs(image, di, dj, base, newColor);
                }
            }
        }
    }
};