/*
 * @Author: Hata
 * @Date: 2020-07-08 10:40:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-08 10:41:32
 * @FilePath: \LeetCode\31.cpp
 * @Description: https://leetcode-cn.com/problems/next-permutation/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        auto it = std::is_sorted_until(nums.rbegin(), nums.rend());
        if (it != nums.rend())
            std::iter_swap(it, std::upper_bound(nums.rbegin(), it, *it));
        std::reverse(nums.rbegin(), it);
    }
};