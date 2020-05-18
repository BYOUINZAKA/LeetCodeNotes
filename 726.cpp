/*
 * @Author: Hata
 * @Date: 2020-05-18 15:36:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-18 17:20:49
 * @FilePath: \LeetCode\726.cpp
 * @Description: https://leetcode-cn.com/problems/number-of-atoms/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using Iter = std::string::iterator;
    std::string countOfAtoms(std::string &formula)
    {
        std::stack<std::map<std::string, int>> stack;
        stack.emplace();
        for (auto it = formula.begin(); it != formula.end();)
        {
            auto left = it;
            if (*left == '(')
            {
                stack.emplace();
                ++it;
            }
            else if (*left == ')')
            {
                int k = 0;
                auto ans = stack.top();
                stack.pop();
                it = stoi(k, left + 1, formula.end());
                for (auto &&pair : ans)
                    (stack.top())[pair.first] += pair.second * k;
            }
            else if (*left >= 'A' && *left <= 'Z')
            {
                int k = 0;
                it = std::find_if_not(left + 1, formula.end(), [](const auto &c) { return c >= 'a' && c <= 'z'; });
                std::string sub = formula.substr(left - formula.begin(), it - left);
                it = stoi(k, it, formula.end());
                (stack.top())[sub] += (k == 0 ? 1 : k);
            }
        }
        auto map = stack.top();
        std::string res;
        for (auto &&pair : map)
        {
            res.append(pair.first);
            if (pair.second != 1)
                res.append(std::to_string(pair.second));
        }
        return res;
    }

    Iter stoi(int &k, Iter begin, Iter end)
    {
        return std::find_if_not(begin, end, [&k](const auto &c) {
            if (c >= '0' && c <= '9')
            {
                k = k * 10 + (c - '0');
                return true;
            }
            else
                return false;
        });
    }
};