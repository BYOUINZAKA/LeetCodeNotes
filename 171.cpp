/*
 * @Author: Hata
 * @Date: 2020-05-07 14:09:05
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 14:12:40
 * @FilePath: \LeetCode\171.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int titleToNumber(const std::string &s)
    {
        int res = 0;
        for (auto &&c : s)
        {
            res = res * 26 + (c - 64);
        }
        return res;
    }
};

int main(){
    Solution s;
    std::cout << s.titleToNumber("ZY") << std::endl;
}