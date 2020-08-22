/*
 * @Author: Hata
 * @Date: 2020-08-03 09:53:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-03 21:13:29
 * @FilePath: \LeetCode\1456.cpp
 * @Description:
 * https://leetcode-cn.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 */

#include <bits/stdc++.h>

class Solution {
    static constexpr const char alphabet[] = {'a', 'e', 'i', 'o', 'u'};

public:
    int maxVowels(std::string& s, const int k) {
        const int N = s.length();

        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += isVowel(s[i]);
        }

        int res = cnt;

        for (int l = 0, r = k; r < N; ++r, ++l) {
            cnt -= isVowel(s[l]);
            cnt += isVowel(s[r]);
            
            res = std::max(res, cnt);
        }

        return res;
    }

    constexpr bool isVowel(char c) {
        for (auto&& i : alphabet) {
            if (i == c) return true;
        }
        return false;
    }
};