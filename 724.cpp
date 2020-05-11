/*
 * @Author: Hata
 * @Date: 2020-05-11 14:21:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 14:33:25
 * @FilePath: \LeetCode\724.cpp
 * @Description: https://leetcode-cn.com/problems/find-pivot-index/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int pivotIndex(std::vector<int> &nums)
    {
        int sum = 0;
        std::vector<int> left{0};
        for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        {
            sum += *it;
            left.push_back(left.back() + *it);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (left[i] == sum - left[i] - nums[i])
                return i;
        }

        return -1;
    }
};