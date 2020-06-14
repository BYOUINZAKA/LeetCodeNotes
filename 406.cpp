/*
 * @Author: Hata
 * @Date: 2020-06-14 22:25:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-14 23:06:24
 * @FilePath: \LeetCode\406.cpp
 * @Description: https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
    {
        std::sort(people.begin(), people.end(), [](auto &&lhs, auto &&rhs) {
            return lhs.front() != rhs.front() ? lhs.front() > rhs.front() : lhs.back() < rhs.back();
        });
        std::list<std::vector<int>> list;
        for (auto &&v : people)
        {
            auto it = std::next(list.begin(), v.back());
            list.insert(it, v);
        }
        return std::vector<std::vector<int>>(list.begin(), list.end());
    }
};