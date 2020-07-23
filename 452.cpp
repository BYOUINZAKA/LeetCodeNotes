/*
 * @Author: Hata
 * @Date: 2020-07-21 21:26:04
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-21 21:35:28
 * @FilePath: \LeetCode\452.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>> &points) {
        if (points.empty()) return 0;

        std::sort(points.begin(), points.end(),
                  [](auto &&p1, auto &&p2) { return p1.back() < p2.back(); });
        auto end = points.front().back();

        int res = 1;
        for (auto &&p : points) {
            if (p.front() > end) {
                ++res;
                end = p.back();
            }
        }
        return res;
    }
};