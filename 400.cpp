/*
 * @Author: Hata
 * @Date: 2020-05-22 15:32:10
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-22 15:43:01
 * @FilePath: \LeetCode\400.cpp
 * @Description: https://leetcode-cn.com/problems/nth-digit/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int findNthDigit(int n)
    {
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            ++digits;
        }
        int idx = n % digits;
        if (idx == 0)
            idx = digits;
        long number = 1;
        for (int i = 1; i < digits; i++)
            number *= 10;
        number += (idx == digits) ? n / digits - 1 : n / digits;

        for (int i = idx; i < digits; i++)
            number /= 10;
        return number % 10;
    }
};