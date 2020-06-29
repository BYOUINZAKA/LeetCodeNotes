/*
 * @Author: Hata
 * @Date: 2020-06-24 18:52:13
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-24 18:54:47
 * @FilePath: \LeetCode\1374.cpp
 * @Description: 
 */
#include <bits/stdc++.h>

class Solution
{
public:
    template <typename T = int>
    typename std::enable_if_t<
        std::is_integral_v<std::remove_reference_t<T>>,
        std::string>
    generateTheString(T &&n)
    {
        std::string res(std::forward<T>(n), 'a');
        if ((std::forward<T>(n) & 1) == 0)
        {
            res.back() = 'b';
        }
        return res;
    }
};