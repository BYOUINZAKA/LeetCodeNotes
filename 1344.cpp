/*
 * @Author: Hata
 * @Date: 2020-05-24 15:45:50
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 15:46:50
 * @FilePath: \LeetCode\1344.cpp
 * @Description: https://leetcode-cn.com/problems/angle-between-hands-of-a-clock/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double mAngle = minutes * 6;
        double hAngle = hour * 30 + mAngle / 12.0;
        double ans = fabs(mAngle - hAngle);
        return std::min(ans, 360 - ans);
    }
};