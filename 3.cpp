/*
 * @Author: Hata
 * @Date: 2020-05-03 22:24:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 11:42:39
 * @FilePath: \LeetCode\3.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string &s)
    {
        std::size_t max = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            std::string sub = s.substr(i, 1);
            int pos = -1;
            for (int j = i + 1; j < s.length(); ++j)
            {
                if (pos = sub.find(s[j]), pos == std::string::npos)
                {
                    sub.push_back(s[j]);
                }
                else
                {
                    i += pos;
                    break;
                }
            }
            max = std::max(max, sub.length());
        }
        return max;
    }
};