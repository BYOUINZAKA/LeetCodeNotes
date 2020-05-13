/*
 * @Author: Hata
 * @Date: 2020-05-13 13:28:28
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-13 13:48:59
 * @FilePath: \LeetCode\454.cpp
 * @Description: https://leetcode-cn.com/problems/4sum-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D)
    {
        std::unordered_map<int, int> map_ab;
        int res = 0;

        for (auto &&a : A)
            for (auto &&b : B)
                ++map_ab[a + b];

        for (auto &&c : C)
        {
            for (auto &&d : D)
            {
                auto it = map_ab.find(0 - c - d);
                if (it != map_ab.end())
                    res += it->second;
            }
        }

        return res;
    }
};