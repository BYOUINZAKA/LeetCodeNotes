/*
 * @Author: Hata
 * @Date: 2020-07-10 19:41:20
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-10 19:43:27
 * @FilePath: \LeetCode\504.cpp
 * @Description: https://leetcode-cn.com/problems/base-7/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string convertToBase7(int num)
    {
        if (num < 0)
            return "-" + convertToBase7(-num);
        if (num < 7)
            return std::to_string(num);
        return convertToBase7(num / 7) + std::to_string(num % 7);
    }
};