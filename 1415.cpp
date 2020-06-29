/*
 * @Author: Hata
 * @Date: 2020-06-22 20:00:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-22 20:26:56
 * @FilePath: \LeetCode\1415.cpp
 * @Description: https://leetcode-cn.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
 */
#include <bits/stdc++.h>

class Solution
{
    std::string res;

public:
    std::string getHappyString(int n, int k)
    {
        std::string paths;
        backtrack(n, k, paths, 'a');
        return res;
    }

    void backtrack(int n, int k, std::string &paths, char c)
    {
        paths.push_back(c);
        if (paths.length() == n)
            --k;
        if (k == 0)
        {
            res = paths;
            return;
        }
        else
        {
            auto &&[c1, c2] = without(c);
            backtrack(n, k, paths, c1);
            paths.pop_back();
            backtrack(n, k, paths, c2);
            paths.pop_back();
        }
    }

    std::tuple<char, char> without(char c)
    {
        switch (c)
        {
        case 'a':
            return std::make_tuple('b', 'c');
        case 'b':
            return std::make_tuple('a', 'c');
        case 'c':
            return std::make_tuple('a', 'b');
        default:
            break;
        }
    }
};