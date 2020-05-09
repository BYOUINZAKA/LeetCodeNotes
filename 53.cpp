/*
 * @Author: Hata
 * @Date: 2020-05-06 12:48:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 12:56:32
 * @FilePath: \LeetCode\53.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        std::vector<int> dp = nums;
        int res = dp.front();
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            res = std::max(dp[i], res);
        }
        return res;
    }
};