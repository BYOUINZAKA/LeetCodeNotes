/*
 * @Author: Hata
 * @Date: 2020-05-21 13:44:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 13:45:30
 * @FilePath: \LeetCode\1266.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-time-visiting-all-points/
 */
#include <bits/stdc++.h>
class Solution
{
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>> &points)
    {
        int x0 = points[0][0], x1 = points[0][1];
        int ans = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            int y0 = points[i][0], y1 = points[i][1];
            ans += std::max(abs(x0 - y0), abs(x1 - y1));
            x0 = y0;
            x1 = y1;
        }
        return ans;
    }
};