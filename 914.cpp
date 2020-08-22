/*
 * @Author: Hata
 * @Date: 2020-08-03 21:14:55
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-03 21:29:12
 * @FilePath: \LeetCode\914.cpp
 * @Description: https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
 */

#include <bits/stdc++.h>

class Solution {
    int cnt[10000];

public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        for (auto&& x : deck) cnt[x]++;
        int g = -1;
        for (int i = 0; i < 10000; ++i)
            if (cnt[i]) {
                if (~g)
                    g = std::gcd(g, cnt[i]);
                else
                    g = cnt[i];
            }
        return g >= 2 ? true : false;
    }
};