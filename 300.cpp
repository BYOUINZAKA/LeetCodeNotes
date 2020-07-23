/*
 * @Author: Hata
 * @Date: 2020-07-14 16:14:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-14 16:25:48
 * @FilePath: \LeetCode\300.cpp
 * @Description: https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums) {
        const int kSize = nums.size();
        if (kSize == 0) return 0;

        std::vector<int> dp(kSize, 1);

        for (int i = 1; i < kSize; ++i) {
            int max_sub = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) max_sub = std::max(max_sub, dp[j]);
            }
            dp[i] += max_sub;
        }

        return *std::max_element(dp.cbegin(), dp.cend());
    }
};