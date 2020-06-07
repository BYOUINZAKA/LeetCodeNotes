/*
 * @Author: Hata
 * @Date: 2020-06-07 16:51:44
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-07 16:58:40
 * @FilePath: \LeetCode\930.cpp
 * @Description: https://leetcode-cn.com/problems/binary-subarrays-with-sum/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int numSubarraysWithSum(std::vector<int> &A, int S)
    {
        std::unordered_map<int, int> table{{0, 1}};
        int res = 0, s = 0;
        for (auto &&i : A)
        {
            s += i;
            res += table[s - S];
            ++table[s];
        }
        return res;
    }
};