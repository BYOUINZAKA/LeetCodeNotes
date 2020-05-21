/*
 * @Author: Hata
 * @Date: 2020-05-21 19:44:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 20:04:56
 * @FilePath: \LeetCode\875.cpp
 * @Description: https://leetcode-cn.com/problems/koko-eating-bananas/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int minEatingSpeed(std::vector<int> &piles, int H)
    {
        int left = 1;
        int right = *std::max_element(piles.cbegin(), piles.cend());
        int mid, res;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (check(piles, H, mid))
            {
                right = mid - 1;
                res = mid;
            }
            else
                left = mid + 1;
        }
        return res;
    }

    bool check(std::vector<int> &piles, int H, int k)
    {
        int sum = 0;
        for (int p : piles)
        {
            sum += (p == k ? 1 : p / k + 1);
            if (sum > H)
                return false;
        }
        return true;
    }
};