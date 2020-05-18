/*
 * @Author: Hata
 * @Date: 2020-05-18 20:22:07
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-18 20:24:50
 * @FilePath: \LeetCode\1450.cpp
 * @Description: https://leetcode-cn.com/problems/number-of-students-doing-homework-at-a-given-time/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int busyStudent(std::vector<int> &startTime, std::vector<int> &endTime, int queryTime)
    {
        auto size = startTime.size();
        int count = 0;
        for (int i = 0; i < size; ++i)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
                ++count;
        }
        return count;
    }
};