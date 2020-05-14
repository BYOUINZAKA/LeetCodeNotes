/*
 * @Author: Hata
 * @Date: 2020-05-14 23:18:41
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-14 23:50:06
 * @FilePath: \LeetCode\841.cpp
 * @Description: https://leetcode-cn.com/problems/keys-and-rooms/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using Iter = std::vector<std::vector<int>>::iterator;
    std::vector<int> record;
    bool canVisitAllRooms(std::vector<std::vector<int>> &rooms)
    {
        record = std::vector<int>(rooms.size(), 0);
        bfs(rooms.begin(), rooms.begin());
        return std::all_of(record.begin(), record.end(), [](const auto &i) { return i > 0; });
    }

    void bfs(Iter base, Iter p)
    {
        ++record[p - base];
        std::for_each(p->begin(), p->end(), [&](const auto &i) {
            if (record[i] == 0)
                bfs(base, base + i);
        });
    }
};