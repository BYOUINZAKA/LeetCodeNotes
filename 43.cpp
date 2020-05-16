/*
 * @Author: Hata
 * @Date: 2020-05-15 14:29:06
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-16 00:16:38
 * @FilePath: \LeetCode\43.cpp
 * @Description: https://leetcode-cn.com/problems/multiply-strings/solution/
 */
#include <bits/stdc++.h>

/*
class Solution
{
public:
    static std::string NULLSTR;
    std::string multiply(std::string num1, std::string num2)
    {
        if (num1 == NULLSTR || num2 == NULLSTR)
            return NULLSTR;
        std::vector<std::string> for_add;
        std::size_t maxlen = 0;

        int count = 0;
        std::for_each(num2.rbegin(), num2.rend(), [&](const auto &a) {
            int value = a - '0';
            int flag = 0;
            std::string s1(count, '0');
            if (value == 1)
            {
                s1.append(num1);
            }
            else
                std::for_each(num1.rbegin(), num1.rend(), [&](const auto &b) {
                    int mut = (b - '0') * value + flag;
                    int v = mut % 10;
                    flag = (mut - v) / 10;
                    s1.push_back(v + '0');
                });
            if (flag != 0)
                s1.push_back(flag + '0');
            for_add.push_back(s1);
            maxlen = std::max(maxlen, s1.length());
            ++count;
        });
        auto res = addAll(for_add, maxlen);
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string addAll(const std::vector<std::string> &nums, std::size_t maxlen)
    {
        std::string res;
        int flag = 0;
        for (auto i = 0; i < maxlen; ++i)
        {
            int value = flag;
            std::for_each(nums.begin(), nums.end(), [&](const auto &s) {
                value += i < s.length() ? (s[i] - '0') : 0;
            });
            int v = value % 10;
            flag = (value - v) / 10;
            res.push_back(v + '0');
        }
        if (flag != 0)
            res.push_back(flag + '0');
        return res;
    }
};

std::string Solution::NULLSTR = "0";
*/

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        std::string res{"0"};
        if (num1 == res || num2 == res)
            return res;
        int count = 0;
        std::for_each(num2.rbegin(), num2.rend(), [&](const auto &a) {
            int value = a - '0';
            int flag = 0;
            std::string s1(count, '0');
            std::for_each(num1.rbegin(), num1.rend(), [&](const auto &b) {
                int mut = (b - '0') * value + flag;
                int v = mut % 10;
                flag = (mut - v) / 10;
                s1.push_back(v + '0');
            });
            if (flag != 0)
                s1.push_back(flag + '0');
            cout << res << endl;
            res = add(res, s1);
            ++count;
        });
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string add(const std::string &a, const std::string &b)
    {
        std::string res;
        int flag = 0;
        auto maxlen = std::max(a.length(), b.length());
        for (int i = 0; i < maxlen; ++i)
        {
            int v = flag + (i < a.length() ? (a[i] - '0') : 0) + (i < b.length() ? (b[i] - '0') : 0);
            int value = v % 10;
            flag = (v - value) / 10;
            res.push_back(value + '0');
        }
        if (flag == 1)
            if (res.back() + 1 > '9')
                res.push_back('1');
            else
                ++res.back();
        return res;
    }
};