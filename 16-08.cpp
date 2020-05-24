/*
 * @Author: Hata
 * @Date: 2020-05-23 13:18:38
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-23 13:27:56
 * @FilePath: \LeetCode\16-08.cpp
 * @Description: https://leetcode-cn.com/problems/english-int-lcci/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    constexpr static const char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                                           "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                           "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    constexpr static const char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    constexpr static const char *gens[] = {"Billion", "Million", "Thousand", ""};

    std::string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        std::string res;
    }
};