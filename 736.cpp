/*
 * @Author: Hata
 * @Date: 2020-05-18 18:21:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-18 19:36:48
 * @FilePath: \LeetCode\736.cpp
 * @Description: https://leetcode-cn.com/problems/parse-lisp-expression/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    enum class Type
    {
        let,
        add,
        mult
    };
    using ExpTree = std::tuple<Type, int *, std::unordered_map<std::string, int>>;

    const static constexpr int undefinded = std::numeric_limits<int>::max();

    int evaluate(std::string &expression)
    {
        std::stack<ExpTree> var_table;

        for (auto it = expression.begin(); it != expression.end();)
        {
            if (*it == '(')
            {
                it = subType(var_table, it, expression.end());
            }
            else if (*it == ')')
            {
            }
            else
            {
                auto back = std::find_if(
                    it,
                    expression.end(),
                    [](const auto &c) { return c == ' ' || c == ')'; });
                std::string sub = expression.substr(it - expression.begin(), back - it);
                // std::cout << sub << std::endl;
                auto type = std::get<0>(var_table.top());
                auto res = std::get<1>(var_table.top());
                auto table = std::get<2>(var_table.top());
                if (type == Type::add || type == Type::mult)
                {
                    int value = 0;
                    try
                    {
                        value = std::stoi(sub);
                    }
                    catch (std::invalid_argument)
                    {
                        
                    }
                }
                else if (type == Type::let)
                {
                    if (res == nullptr)
                    {
                        res = &table[sub];
                    }
                    else if (*res == undefinded)
                    {
                    }
                }
                it = back;
            }
            it = std::find_if_not(it + 1, expression.end(), [](const auto &c) { return c == ' '; });
        }

        return 0;
    }

    std::string::iterator subType(std::stack<ExpTree> &table, std::string::iterator iter, std::string::iterator end)
    {
        switch (*(iter + 1))
        {
        case 'l':
            table.emplace(Type::let, nullptr, std::unordered_map<std::string, int>{});
            break;

        case 'a':
            table.emplace(Type::add, nullptr, std::unordered_map<std::string, int>{});
            break;

        case 'm':
            table.emplace(Type::mult, nullptr, std::unordered_map<std::string, int>{});
            break;
        }
        return std::find(iter + 3, end, ' ');
    }
};