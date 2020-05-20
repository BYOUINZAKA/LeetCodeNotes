/*
 * @Author: Hata
 * @Date: 2020-05-20 18:34:13
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 18:36:15
 * @FilePath: \LeetCode\233.cpp
 * @Description: https://leetcode-cn.com/problems/number-of-digit-one/solution/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int countDigitOne(int n)
    {
        if (n <= 0)
            return 0;
        int ans = 0;
        int left, right = 0, idx = 0, cur = 0;
        while (n)
        {
            cur = n % 10;
            left = n / 10;
            if (cur == 0)
            {
                ans += left * std::pow(10, idx);
            }
            else if (cur == 1)
            {
                ans += left * std::pow(10, idx) + right + 1;
            }
            else
            {
                ans += (left + 1) * std::pow(10, idx);
            }
            right += cur * std::pow(10, idx);
            n /= 10;
            idx++;
        }
        return ans;
    }
};