/*
 * @Author: Hata
 * @Date: 2020-06-30 14:26:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 14:26:46
 * @FilePath: \LeetCode\732.cpp
 * @Description: https://leetcode-cn.com/problems/my-calendar-iii/
 */
#include <bits/stdc++.h>

class MyCalendarThree
{
    std::map<int, int> table;

public:
    MyCalendarThree()
        : table{}
    {
    }

    int book(int start, int end)
    {
        auto &&sit = table.try_emplace(start, 0).first;
        auto &&eit = table.try_emplace(end, 0).first;

        ++sit->second;
        --eit->second;

        int res = 0, total = 0;
        for (auto &&p : table)
        {
            total += p.second;
            res = std::max(res, total);
        }

        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */