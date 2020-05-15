/*
 * @Author: Hata
 * @Date: 2020-05-15 13:32:41
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-15 14:21:41
 * @FilePath: \LeetCode\1324.cpp
 * @Description: https://leetcode-cn.com/problems/print-words-vertically/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::string> printVertically(std::string &s)
    {
        std::stringstream strin(s);
        std::vector<std::string> strs;
        int max = 0;
        for (std::string str; strin >> str;)
        {
            strs.push_back(str);
            max = std::max(max, int(str.length()));
        }
        std::vector<std::string> res;
        for (int i = 0; i < max; ++i)
        {
            std::string sub;
            for (auto &&s : strs)
            {
                sub.push_back(i < s.size() ? s[i] : ' ');
            }
            while (sub.back() == ' ')
                sub.pop_back();
            res.push_back(sub);
        }
        return res;
    }
};