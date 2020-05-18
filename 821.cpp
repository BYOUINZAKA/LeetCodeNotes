/*
 * @Author: Hata
 * @Date: 2020-05-17 13:31:13
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-17 13:34:34
 * @FilePath: \LeetCode\821.cpp
 * @Description: https://leetcode-cn.com/problems/shortest-distance-to-a-character/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> shortestToChar(std::string &S, char C)
    {
        int left = -10000;
        int right = S.find_first_of(C);
        if (right == -1)
            return {};
        std::vector<int> res;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                res.push_back(0);
                left = right;
                right = S.find_first_of(C, left + 1);
                if (right == -1)
                    right = INT_MAX;
            }
            else
            {
                res.push_back(std::min(i - left, right - i));
            }
        }
        return res;
    }
};