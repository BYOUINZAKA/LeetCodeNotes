/*
 * @Author: Hata
 * @Date: 2020-05-11 13:59:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 14:11:50
 * @FilePath: \LeetCode\630.cpp
 * @Description: https://leetcode-cn.com/problems/course-schedule-iii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int scheduleCourse(std::vector<std::vector<int>> &courses)
    {
        std::sort(courses.begin(), courses.end(), [](const auto &a, const auto &b) {
            return a.back() < b.back();
        });
        std::priority_queue<int> queue;
        int day = 0;
        for (auto &&pair : courses)
        {
            queue.push(pair.front());
            day += pair.front();

            if (day > pair.back())
            {
                day -= queue.top();
                queue.pop();
            }
        }
        return queue.size();
    }
};