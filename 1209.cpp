/*
 * @Author: Hata
 * @Date: 2020-05-21 11:29:01
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 11:48:00
 * @FilePath: \LeetCode\1209.cpp
 * @Description: https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/solution/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string removeDuplicates(std::string &s, int k)
    {
        std::deque<std::string> stack;
        std::for_each(
            s.begin(),
            s.end(),
            [&stack, &k](auto &&c) {
                if (stack.empty() || stack.back().back() != c)
                    stack.push_back({c});
                else
                    stack.back().push_back(c);

                if (stack.back().size() >= k)
                    stack.pop_back();
            });
        std::string res = stack.front();
        stack.pop_front();
        while (!stack.empty())
        {
            res.append(stack.front());
            stack.pop_front();
        }
        return res;
    }
};