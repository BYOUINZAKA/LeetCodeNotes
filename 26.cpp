/*
 * @Author: Hata
 * @Date: 2020-05-11 15:12:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 15:12:22
 * @FilePath: \LeetCode\26.cpp
 * @Description: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        return std::unique(nums.begin(), nums.end()) - nums.begin();
    }
};