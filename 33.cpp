/*
 * @Author: Hata
 * @Date: 2020-06-30 15:24:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 15:27:19
 * @FilePath: \LeetCode\33.cpp
 * @Description: https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int n = (int)nums.size();
        if (!n)
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};