/*
 * @Author: Hata
 * @Date: 2020-05-06 12:59:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 13:40:54
 * @FilePath: \LeetCode\303.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class NumArray
{
    std::vector<int> dp;

public:
    NumArray(std::vector<int> &nums)
    {
        dp = std::vector<int>(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i)
            dp[i] = dp[i - 1] + nums[i - 1];
    }

    int sumRange(int i, int j)
    {
        return dp[j + 1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */