/*
 * @Author: Hata
 * @Date: 2020-07-15 15:12:29
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-15 15:24:27
 * @FilePath: \LeetCode\1190.cpp
 * @Description:
 * https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::string reverseParentheses(std::string &s) {
        std::stack<std::string> stack;
        stack.emplace();

        for (auto &&c : s) {
            if (c == '(')
                stack.emplace();
            else if (c == ')') {
                auto temp = stack.top();
                stack.pop();
                for (auto it = temp.rbegin(); it != temp.rend(); ++it) stack.top().push_back(*it);
            } else
                stack.top().push_back(c);
        }

        return stack.top();
    }
};

int main() {
    const char *s1 = "123";
    const char *s2 = "123";
    std::cout << (s1==s2) <<std::endl;
}