/*
 * @Author: Hata
 * @Date: 2020-06-08 18:25:54
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-08 18:28:32
 * @FilePath: \LeetCode\190.cpp
 * @Description: https://leetcode-cn.com/problems/reverse-bits/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int _ = 0; _ < 32; ++_)
        {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};