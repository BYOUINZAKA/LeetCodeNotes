/*
 * @Author: Hata
 * @Date: 2020-05-16 16:06:54
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-16 17:03:29
 * @FilePath: \LeetCode\1016.cpp
 * @Description: https://leetcode-cn.com/problems/binary-string-with-substrings-representing-1-to-n/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    bool queryString(std::string &S, int N)
    {
        std::string num{"1"};
        for (int i = 1; i <= N; ++i)
        {
            if (std::search(S.begin(), S.end(),
                            std::boyer_moore_horspool_searcher(
                                num.rbegin(), num.rend())) == S.end())
                return false;
            inc(num);
        }
        return true;
    }

    void inc(std::string &num)
    {
        auto pos = std::find(num.begin(), num.end(), '0');
        std::fill(num.begin(), pos, '0');
        if (pos == num.end())
            num.push_back('1');
        else
            ++(*pos);
    }
};