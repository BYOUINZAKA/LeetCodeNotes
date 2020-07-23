/*
 * @Author: Hata
 * @Date: 2020-07-02 19:09:23
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-02 20:45:49
 * @FilePath: \LeetCode\224.cpp
 * @Description: https://leetcode-cn.com/problems/basic-calculator/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using OperNode = std::variant<int, char>;
    enum
    {
        NUMBER,
        OPERATOR
    };

public:
    int calculate(std::string &s)
    {
        std::stack<OperNode> stack;
        for (auto it = s.crbegin(); it != s.crend(); ++it)
        {
            it = std::find_if_not(it, s.crend(), [](auto &&c) { return c == ' '; });
            if (it == s.crend())
                break;
            if (std::isdigit(*it))
            {
                std::vector<int> nums;
                it = std::prev(std::find_if_not(it, s.crend(), [&nums](auto &&c) {
                    if (std::isdigit(c))
                    {
                        nums.push_back(c - '0');
                        return true;
                    }
                    return false;
                }));
                int value = 0;
                for (auto num_it = nums.rbegin(); num_it != nums.rend(); ++num_it)
                {
                    value = value * 10 + *num_it;
                }
                stack.push(value);
            }
            else if (*it != '(')
            {
                stack.push(*it);
            }
            else
            {
                stack.push(compute(stack));
            }
        }
        return compute(stack);
    }

    int compute(std::stack<OperNode> &simple_stack)
    {
        int value = 0;
        bool is_add = true;
        while (!simple_stack.empty())
        {
            auto op = simple_stack.top();
            simple_stack.pop();
            if (op.index() == OPERATOR)
            {
                if (std::get<OPERATOR>(op) == ')')
                    break;
                is_add = (std::get<OPERATOR>(op) == '+');
            }
            else
            {
                value += is_add ? std::get<NUMBER>(op) : -std::get<NUMBER>(op);
            }
        }
        return value;
    }
};

int main()
{
    Solution solution;
    std::string s1 = "2-4-(8+2-6+(8+4-(1)+8-10))";
    std::string s2 = "(1+(4+5+2)-3)+(6+8)";
    std::cout << solution.calculate(s1) << std::endl;
    std::cout << solution.calculate(s2) << std::endl;
}