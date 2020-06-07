/*
 * @Author: Hata
 * @Date: 2020-06-04 17:53:50
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 18:01:59
 * @FilePath: \LeetCode\516.cpp
 * @Description: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int longestPalindromeSubseq(const std::string &s)
    {
        int length = s.length();
        std::vector<std::vector<int>> dp(length, std::vector<int>(length, 0));
        for (int n = 0; n < length; ++n)
            dp[n][n] = 1;
        for (int i = length - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp.front().back();
    }
};