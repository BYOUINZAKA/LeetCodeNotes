/*
 * @Author: Hata
 * @Date: 2020-05-18 13:34:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-18 15:31:00
 * @FilePath: \LeetCode\394.cpp
 * @Description: https://leetcode-cn.com/problems/decode-string/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string decodeString(std::string &s)
    {
        std::stack<std::pair<int, std::string>> stack;
        stack.emplace(1, "");
        int k = 0;
        for (auto &&c : s)
        {
            if (c == '[')
            {
                stack.emplace(k, "");
                k = 0;
            }
            else if (c == ']')
            {
                auto ans = stack.top();
                stack.pop();
                for (int i = 0; i < ans.first; ++i)
                {
                    stack.top().second.append(ans.second);
                }
            }

            else if (c <= '9' && c >= '0')
                k = k * 10 + (c - '0');

            else
                stack.top().second.push_back(c);
        }
        return stack.top().second;
    }
};