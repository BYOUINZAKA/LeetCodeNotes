/*
 * @Author: Hata
 * @Date: 2020-06-11 15:56:03
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-11 16:09:41
 * @FilePath: \LeetCode\150.cpp
 * @Description: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> exprs;
        for (auto &&s : tokens)
        {
            if (std::isdigit(s.back()))
            {
                exprs.push(std::stoi(s));
            }
            else
            {
                int right = exprs.top();
                exprs.pop();
                int left = exprs.top();
                exprs.pop();
                exprs.push(compute(left, right, s.back()));
            }
        }
        return exprs.top();
    }

    int compute(int left, int right, char exp)
    {
        switch (exp)
        {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        }
        return 0;
    }
};