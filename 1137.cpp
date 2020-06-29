/*
 * @Author: Hata
 * @Date: 2020-06-23 00:22:42
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-23 01:25:19
 * @FilePath: \LeetCode\1137.cpp
 * @Description: https://leetcode-cn.com/problems/n-th-tribonacci-number/
 */
#include <bits/stdc++.h>

template <int N>
struct Tribonacci
{
    constexpr static int value = Tribonacci<N - 1>::value + Tribonacci<N - 2>::value + Tribonacci<N - 3>::value;
};

template <>
struct Tribonacci<0>
{
    constexpr static int value = 0;
};

template <>
struct Tribonacci<1>
{
    constexpr static int value = 1;
};

template <>
struct Tribonacci<2>
{
    constexpr static int value = 1;
};

class Solution
{
    template <int N, int... Args>
    struct Unpack
    {
        constexpr static int get(int n)
        {
            return Unpack<N - 1, N, Args...>::get(n);
        }
    };

    template <int... Args>
    struct Unpack<0, Args...>
    {
        constexpr static int get(int n)
        {
            constexpr int list[] = {Tribonacci<0>::value, Tribonacci<Args>::value...};
            return list[n];
        }
    };

public:
    int tribonacci(int n)
    {
        return Unpack<37>::get(n);
    }
};

int main()
{
    Solution solution;
    for (int i = 0; i < 38; ++i)
        std::cout << solution.tribonacci(i) << std::endl;
}