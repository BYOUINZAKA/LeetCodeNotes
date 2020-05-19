/*
 * @Author: Hata
 * @Date: 2020-05-19 19:55:42
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-19 20:12:50
 * @FilePath: \LeetCode\162.cpp
 * @Description: https://leetcode-cn.com/problems/find-peak-element/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> nums;
    int findPeakElement(std::vector<int> &nums)
    {
        this->nums = nums;
        int right = nums.size() - 1, left = 0;
        int mid = (right + left) / 2;
        while (left < right)
        {
            int sw = comp(mid);
            if (sw == 0)
                return mid;
            else if (sw == 1)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (right + left) / 2;
        }
        return left;
    }

    int comp(int v)
    {
        int left = v - 1 >= 0 ? nums[v - 1] : std::numeric_limits<int>::min();
        int right = v + 1 < nums.size() ? nums[v + 1] : std::numeric_limits<int>::min();
        if (nums[v] >= left && nums[v] >= right)
            return 0;
        else if (left >= nums[v] && nums[v] >= right)
            return -1;
        else if (right >= nums[v] && nums[v] >= left)
            return 1;
        return left > right ? -1 : 1;
    }
};