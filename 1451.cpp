/*
 * @Author: Hata
 * @Date: 2020-05-24 01:48:25
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 01:57:38
 * @FilePath: \LeetCode\1451.cpp
 * @Description: https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string arrangeWords(std::string &text)
    {
        std::vector<std::string> array;
        int n = text.size();
        text.front() -= ('A' - 'a');
        std::string tmp;
        for (int i = 0; i <= n; i++)
        {
            if (text[i] == ' ' || i == n)
            {
                array.push_back(tmp);
                tmp = "";
            }
            else
                tmp += text[i];
        }
        std::stable_sort(array.begin(), array.end(), [](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
        std::string res;
        for (auto &&s : array)
        {
            res += s;
            if (res.size() != n)
                res += ' ';
        }
        res.front() += 'A' - 'a';
        return res;
    }
};