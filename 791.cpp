/*
 * @Author: Hata
 * @Date: 2020-07-29 16:56:55
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-29 17:14:12
 * @FilePath: \LeetCode\791.cpp
 * @Description: https://leetcode-cn.com/problems/custom-sort-string/
 */

#include <bits/stdc++.h>

class Solution {
    std::array<int, 26> table = {0};

public:
    std::string customSortString(std::string &S, std::string &T) {
        const int N = S.length();
        for (int i = 0; i < N; ++i) indexOf(S[i]) = i;
        std::sort(T.begin(), T.end(),
                  [&](auto &&lhs, auto &&rhs) { return indexOf(lhs) < indexOf(rhs); });
        return T;
    }

private:
    constexpr int &indexOf(char c) { return table[c - 'a']; }
};