/*
 * @Author: Hata
 * @Date: 2020-05-10 04:48:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-10 05:28:39
 * @FilePath: \LeetCode\17-21.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        auto left = height.begin(), right = height.end() - 1;
        int left_max = *left, right_max = *right;
        int result = 0;
        while (left < right)
        {
            if (left_max < right_max)
            {
                result += left_max - *left;
                ++left;
                left_max = std::max(*left, left_max);
            }
            else
            {
                result += right_max - *right;
                --right;
                right_max = std::max(*right, right_max);
            }
        }
        return result;
    }
};