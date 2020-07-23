/*
 * @Author: Hata
 * @Date: 2020-07-15 16:49:54
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-15 17:15:07
 * @FilePath: \LeetCode\712.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int minimumDeleteSum(std::string& s1, std::string& s2) {
        const int k_n = s1.length(), k_m = s2.length();

        int sum = 0;
        for (auto&& c : s1) sum += int(c);
        for (auto&& c : s2) sum += int(c);
        if (k_n == 0 || k_m == 0) return sum;

        const int k_n_ = k_n + 1, k_m_ = k_m + 1;
        std::vector<int> dp(k_n_ * k_m_, 0);

        for (int i = 1; i <= k_n; ++i) {
            for (int j = 1; j <= k_m; ++j) {
                const int index = i * k_m_ + j;
                if (s1[i - 1] == s2[j - 1])
                    dp[index] = dp[index - (k_m_ + 1)] + int(s1[i - 1]);
                else
                    dp[index] = std::max(dp[index - 1], dp[index - k_m_]);
            }
        }

        return sum - 2 * *std::max_element(dp.begin(), dp.end());
    }
};