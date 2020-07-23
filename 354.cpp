/*
 * @Author: Hata
 * @Date: 2020-07-10 13:03:05
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-10 13:47:40
 * @FilePath: \LeetCode\354.cpp
 * @Description: https://leetcode-cn.com/problems/russian-doll-envelopes/
 */
#include <bits/stdc++.h>

class Solution
{
    template <class T>
    constexpr bool fitInto(T &&base, T &&into) const
    {
        return base[0] < into[0] && base[1] < into[1];
    }

public:
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes)
    {
        const int N = envelopes.size();
        if (N == 0)
            return 0;
            
        std::sort(envelopes.begin(), envelopes.end(), [](auto &&lhs, auto &&rhs) {
            return lhs.front() != rhs.front() ? lhs.front() < rhs.front() : lhs.back() > rhs.back();
        });

        std::vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i)
        {
            int raise = 0;
            for (int j = i - 1; j >= 0; --j)
            {
                if (fitInto(envelopes[j], envelopes[i]))
                    raise = std::max(dp[j], raise);
            }
            dp[i] += raise;
        }
        return *std::max_element(dp.cbegin(), dp.cend());
    }
};