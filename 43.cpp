/*
 * @Author: Hata
 * @Date: 2020-05-15 14:29:06
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 18:11:42
 * @FilePath: \LeetCode\43.cpp
 * @Description: https://leetcode-cn.com/problems/multiply-strings/solution/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string multiply(const std::string &num1, const std::string &num2)
    {
        std::string res{"0"};
        if (num1 == res || num2 == res)
            return res;
        int count = 0;

        std::for_each(num2.rbegin(), num2.rend(), [&](const auto &a) {
            int value = a - '0';
            int flag = 0;
            std::string str(count, '0');
            std::for_each(num1.rbegin(),
                          num1.rend(),
                          [&](const auto &b) {
                              int mut = (b - '0') * value + flag;
                              int v = mut % 10;
                              flag = (mut - v) / 10;
                              str.push_back(v + '0');
                          });

            if (flag != 0)
                str.push_back(flag + '0');
            add(std::move(res), str);
            ++count;
        });

        std::reverse(res.begin(), res.end());
        return res;
    }

    void add(std::string &&a, const std::string &b)
    {
        std::string res;
        int flag = 0;
        auto maxlen = std::max(a.length(), b.length());

        for (int i = 0; i < maxlen; ++i)
        {
            int value = flag + (i < a.length() ? (a[i] - '0') : 0) + (i < b.length() ? (b[i] - '0') : 0);
            int v = value % 10;
            flag = (value - v) / 10;
            res.push_back(v + '0');
        }
        if (flag != 0)
            res.push_back('1');

        a = std::move(res);
    }
};