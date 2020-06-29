/*
 * @Author: Hata
 * @Date: 2020-06-12 23:59:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-29 19:36:41
 * @FilePath: \LeetCode\414.cpp
 * @Description: https://leetcode-cn.com/problems/third-maximum-number/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int thirdMax(std::vector<int> &nums)
    {
        std::set<int> set;
        for (auto &&i : nums)
        {
            set.insert(i);
            if (set.size() > 3)
                set.erase(set.begin());
        }
        if (set.size() < 3)
            return *set.rbegin();
        else
            return *set.begin();
    }
};