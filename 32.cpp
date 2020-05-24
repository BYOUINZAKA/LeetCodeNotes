/*
 * @Author: Hata
 * @Date: 2020-05-24 13:46:49
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 13:47:41
 * @FilePath: \LeetCode\32.cpp
 * @Description: https://leetcode-cn.com/problems/longest-valid-parentheses/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int longestValidParentheses(std::string &s)
    {
        int size = s.length();
        if (size == 0)
            return 0;
        std::vector<int> dp(size, 0);
        int maximum = 0;
        for (int i = 1; i < size; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maximum = std::max(maximum, dp[i]);
        }
        return maximum;
    }
};