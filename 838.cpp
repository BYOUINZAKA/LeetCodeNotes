/*
 * @Author: Hata
 * @Date: 2020-05-21 18:06:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 18:59:44
 * @FilePath: \LeetCode\838.cpp
 * @Description: https://leetcode-cn.com/problems/push-dominoes/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string
    pushDominoes(std::string &dominoes)
    {
        auto findCall = [](const auto &c) {
            return c == 'L' || c == 'R';
        };
        auto begin = std::find_if(dominoes.begin(), dominoes.end(), findCall);
        auto end = std::find_if(dominoes.rbegin(), dominoes.rend(), findCall).base();

        for (auto forward = begin, backward = begin;
             forward != end && backward != end;
             forward = backward)
        {
            backward = std::find_if(forward + 1, end, findCall);
            if (*forward == *backward)
            {
                std::fill(forward, backward, *forward);
            }
            else if (*forward == 'R' && *backward == 'L')
            {
                for (auto it = forward + 1; it != backward; ++it)
                {
                    if (it - forward > backward - it)
                        *it = 'L';
                    else if (it - forward < backward - it)
                        *it = 'R';
                }
            }
        }

        if (*begin == 'L')
            std::fill(dominoes.begin(), begin, 'L');
        if (*(end - 1) == 'R')
            std::fill(end, dominoes.end(), 'R');

        return dominoes;
    }
};