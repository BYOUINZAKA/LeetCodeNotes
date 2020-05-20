/*
 * @Author: Hata
 * @Date: 2020-05-20 16:42:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 16:51:57
 * @FilePath: \LeetCode\910.cpp
 * @Description: https://leetcode-cn.com/problems/smallest-range-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int smallestRangeII(std::vector<int> &A, int K)
    {
        std::sort(A.begin(), A.end());
        int res = A.back() - A.front();

        for (auto it = A.begin(); it != A.end() - 1;)
        {
            int max = std::max(A.back() - K, *it + K);
            int min = std::min(A.front() + K, *(++it) - K);
            res = std::min(res, max - min);
        }

        return res;
    }
};