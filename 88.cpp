/*
 * @Author: Hata
 * @Date: 2020-05-09 14:04:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-09 14:15:43
 * @FilePath: \LeetCode\88.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, std::front_inserter(nums1));
    }
};