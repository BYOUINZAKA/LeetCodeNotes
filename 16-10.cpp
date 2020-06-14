/*
 * @Author: Hata
 * @Date: 2020-06-12 22:31:52
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-12 23:47:10
 * @FilePath: \LeetCode\16-10.cpp
 * @Description: https://leetcode-cn.com/problems/living-people-lcci/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int maxAliveYear(std::vector<int> &birth, std::vector<int> &death)
    {
        std::vector<std::tuple<int, bool>> years;
        for (auto &&i : birth)
            years.emplace_back(i, true);
        for (auto &&i : death)
            years.emplace_back(i + 1, false);
        std::sort(years.begin(), years.end(), [](auto &&lhs, auto &&rhs) {
            return std::get<0>(lhs) < std::get<0>(rhs);
        });

        int liver = 0;
        std::map<int, int> table;
        for (auto it = years.begin(); it != years.end();)
        {
            auto end = std::find_if_not(it, years.end(), [&](auto &&t) {
                return std::get<0>(t) == std::get<0>(*it);
            });
            for (auto p = it; p != end; ++p)
            {
                auto &&[year, type] = *p;
                if (type)
                    ++liver;
                else
                    --liver;
            }
            table.try_emplace(liver, std::get<0>(*it));
            it = end;
        }
        return std::prev(table.end())->second;
    }
};