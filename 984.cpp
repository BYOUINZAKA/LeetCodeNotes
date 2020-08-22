/*
 * @Author: Hata
 * @Date: 2020-08-15 11:45:05
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-15 11:57:42
 * @FilePath: \LeetCode\984.cpp
 * @Description: https://leetcode-cn.com/problems/string-without-aaa-or-bbb/
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::string strWithout3a3b(int A, int B) {
        std::string res;
        const int N = A + B;
        while (A > 0 || B > 0) {
            bool choose;
            const int len = res.length();
            if (len >= 2 && res[len - 1] == res[len - 2]) {
                choose = res.back() == 'b';
            } else {
                choose = A >= B;
            }

            if (choose) {
                --A;
                res.push_back('a');
            } else {
                --B;
                res.push_back('b');
            }
        }
        return res;
    }
};