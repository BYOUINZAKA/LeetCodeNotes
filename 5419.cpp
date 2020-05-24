/*
 * @Author: Hata
 * @Date: 2020-05-24 12:52:12
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 13:26:34
 * @FilePath: \LeetCode\5419.cpp
 * @Description: https://leetcode-cn.com/problems/max-dot-product-of-two-subsequences/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int maxDotProduct(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size()));

        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < n1; ++i)
            dp[i][0] = std::max(dp[i - 1][0], nums1[i] * nums2[0]);
        for (int j = 1; j < n2; ++j)
            dp[0][j] = std::max(dp[0][j - 1], nums1[0] * nums2[j]);
        for (int i = 1; i < n1; ++i)
        {
            for (int j = 1; j < n2; ++j)
            {
                dp[i][j] = std::max({dp[i - 1][j - 1] + nums1[i] * nums2[j], dp[i - 1][j], dp[i][j - 1], nums1[i] * nums2[j]});
            }
        }
        
        return dp.back().back();
    }
};