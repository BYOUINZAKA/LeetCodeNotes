/*
 * @Author: Hata
 * @Date: 2020-06-30 14:24:57
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 14:25:12
 * @FilePath: \LeetCode\693.cpp
 * @Description: https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    bool hasAlternatingBits(long long n)
    {
        long long num = (n ^ (n >> 1)) + 1;
        return (num & (num - 1)) == 0;
    }
};