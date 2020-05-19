/*
 * @Author: Hata
 * @Date: 2020-05-19 19:13:44
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-19 19:31:18
 * @FilePath: \LeetCode\218.cpp
 * @Description: 
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings)
    {
        std::vector<std::pair<int, int>> points;
        for (auto &&b : buildings)
        {
            points.emplace_back(b.front(), -b.back());
            points.emplace_back(b[1], b.back());
        }
        std::sort(points.begin(), points.end());

        std::multiset<int> heights{0};
        std::vector<std::vector<int>> res;
        int prev = 0, cur = 0;

        for (auto &&i : points)
        {
            if (i.second < 0)
                heights.insert(-i.second);
            else
                heights.erase(heights.find(i.second));
            cur = *heights.rbegin();
            if (cur != prev)
            {
                res.push_back({i.first, cur});
                prev = cur;
            }
        }

        return res;
    }
};