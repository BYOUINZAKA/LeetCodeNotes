/*
 * @Author: Hata
 * @Date: 2020-05-06 11:43:56
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 15:52:17
 * @FilePath: \LeetCode\1414.cpp
 * @Description: 和为 K 的最少斐波那契数字数目
 */

#include <bits/stdc++.h>

template <int N>
struct Fibo
// 模板推导类，递归解包。
{
    constexpr static int value = Fibo<N - 1>::value + Fibo<N - 2>::value;
};

template <>
struct Fibo<1>
// 模板偏特化设定递归终止条件。
{
    constexpr static int value = 1;
};

template <>
struct Fibo<0>
// 模板偏特化设定递归终止条件。
{
    constexpr static int value = 1;
};

class Solution
{
    template <int N, int... Args>
    struct Unpack
    {
        static std::vector<int> get()
        {
            return Unpack<N - 1, N, Args...>::get();
        }
    };

    template <int... Args>
    struct Unpack<0, Args...>
    {
        static std::vector<int> get()
        {
            return std::vector<int>{Fibo<0>::value, Fibo<Args>::value...};
        }
    };

public:
    int findMinFibonacciNumbers(int k)
    {
        auto &&list = Unpack<45>::get();
        int res = 0;
        for (auto it = list.rbegin(); it != list.rend(); ++it)
        {
            if (k >= *it)
            {
                ++res;
                k -= *it;
            }
        }
        return res;
    }
};