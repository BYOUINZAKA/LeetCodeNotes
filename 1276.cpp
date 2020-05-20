/*
 * @Author: Hata
 * @Date: 2020-05-19 23:33:48
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-19 23:45:05
 * @FilePath: \LeetCode\1276.cpp
 * @Description: https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        float b = (tomatoSlices - 2 * cheeseSlices) / 2.0;
        float s = cheeseSlices - b;
        if (b - (int)b == 0 && s - (int)s == 0 && s >= 0 && b >= 0)
            return {(int)b, (int)s};
        else
            return {};
    }
};