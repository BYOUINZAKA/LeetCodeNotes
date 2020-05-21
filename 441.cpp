/*
 * @Author: Hata
 * @Date: 2020-05-21 19:00:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 19:14:32
 * @FilePath: \LeetCode\441.cpp
 * @Description: https://leetcode-cn.com/problems/arranging-coins/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int arrangeCoins(int n)
    {
        return (std::sqrt(8 * (long long)n + 1) - 1) / 2;
    }
};