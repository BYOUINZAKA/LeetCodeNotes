/*
 * @Author: Hata
 * @Date: 2020-07-28 10:37:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 10:58:44
 * @FilePath: \LeetCode\1249.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string_view s) {
        std::string res;
        std::stack<int> stack;
        for (auto &&c : s) {
            if (c == ')') {
                if (stack.empty()) continue;
                stack.pop();
            } else if (c == '(') {
                stack.push(res.length());
            }
            res.push_back(c);
        }
        while (!stack.empty()) {
            res.erase(stack.top(), 1);
            stack.pop();
        }
        return res;
    }
};

#include "tools.h"

int main() {
    using namespace lctools;
    std::cout << Formatter::ToString(Solution{}.minRemoveToMakeValid(ToTestCase("lee(t(c)o)de)")));
}