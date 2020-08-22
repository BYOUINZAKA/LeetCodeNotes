/*
 * @Author: Hata
 * @Date: 2020-08-20 12:41:57
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-20 12:48:26
 * @FilePath: \LeetCode\1318.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if (bit_c == 0) {
                ans += bit_a + bit_b;
            } else {
                ans += (bit_a + bit_b == 0);
            }
        }
        return ans;
    }
};