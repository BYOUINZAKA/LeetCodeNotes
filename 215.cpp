/*
 * @Author: Hata
 * @Date: 2020-05-13 13:58:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-13 14:07:08
 * @FilePath: \LeetCode\215.cpp
 * @Description: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};