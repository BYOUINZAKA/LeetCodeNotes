/*
 * @Author: Hata
 * @Date: 2020-05-24 15:06:29
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 15:25:19
 * @FilePath: \LeetCode\739.cpp
 * @Description: https://leetcode-cn.com/problems/daily-temperatures/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &T)
    {
        int size = T.size();
        std::stack<std::pair<int, int>> singleStack;
        std::vector<int> res(size, 0);
        for (int i = 0; i < size; ++i)
        {
            while (!singleStack.empty() && T[i] > singleStack.top().second)
            {
                res[singleStack.top().first] = i - singleStack.top().first;
                singleStack.pop();
            }
            singleStack.emplace(i, T[i]);
        }
        return res;
    }
};