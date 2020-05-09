/*
 * @Author: Hata
 * @Date: 2020-05-05 18:09:56
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-05 18:21:53
 * @FilePath: \LeetCode\921.cpp
 * @Description: 
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int minAddToMakeValid(const std::string &S)
    {
        std::stack<char> stack;
        for (auto &&c : S)
        {
            if (!stack.empty())
            {
                if (stack.top() == '(' && c == ')')
                {
                    stack.pop();
                    continue;
                }
            }
            stack.push(c);
        }
        return stack.size();
    }
};