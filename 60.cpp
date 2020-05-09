/*
 * @Author: Hata
 * @Date: 2020-05-07 21:25:22
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 21:30:12
 * @FilePath: \LeetCode\60.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        std::string str(n, '1');
        std::iota(str.begin(), str.end(), '1');
        for (int i = 1; i < k && std::next_permutation(str.begin(), str.end()); ++i)
            ;
        return str;
    }
};