/*
 * @Author: Hata
 * @Date: 2020-05-22 12:09:51
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-22 12:30:51
 * @FilePath: \LeetCode\982.cpp
 * @Description: https://leetcode-cn.com/problems/triples-with-bitwise-and-equal-to-zero/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int countTriplets(std::vector<int> &A)
    {
        int size = A.size();
        int res = 0;
        std::unordered_map<int, int> table;
        for (auto &&i : A)
        {
            if (i == 0)
            {
                table[0] += size;
                continue;
            }
            for (auto &&j : A)
                ++table[i & j];
        }

        for (auto &&pair : table)
        {
            if (pair.first == 0)
            {
                res += pair.second * size;
                continue;
            }
            for (auto &&i : A)
            {
                if ((pair.first & i) == 0)
                    res += pair.second;
            }
        }
        return res;
    }
};