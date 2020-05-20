/*
 * @Author: Hata
 * @Date: 2020-05-20 16:28:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 16:34:57
 * @FilePath: \LeetCode\125.cpp
 * @Description: https://leetcode-cn.com/problems/valid-palindrome/
 */
#include <bits/stdc++.h>

class Solution
{
    bool isNumOrChar(char c)
    {
        if (tolower(c) >= 'a' && tolower(c) <= 'z' || tolower(c) >= '0' && tolower(c) <= '9')
            return true;
        return false;
    }

public:
    bool isPalindrome(std::string &s)
    {
        int n = s.size();
        if (n == 0)
            return true;
        int low = 0, high = n - 1;
        while (low < high)
        {
            if (!isNumOrChar(s[low]))
                low++;
            if (!isNumOrChar(s[high]))
                high--;
            if (isNumOrChar(s[low]) && isNumOrChar(s[high]))
            {
                if (tolower(s[low]) == tolower(s[high]))
                {
                    low++;
                    high--;
                }
                else
                    return false;
            }
        }
        return true;
    }
};