/*
 * @Author: Hata
 * @Date: 2020-07-10 19:48:19
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-11 13:18:31
 * @FilePath: \LeetCode\122.cpp
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */
#include <bits/stdc++.h>

class Solution {
public:
    template <typename List,
        typename T = typename std::remove_reference_t<List>::value_type>
    typename std::enable_if_t<std::is_arithmetic_v<T>, T>
    maxProfit(List&& prices)
    {
        T res = 0;
        for (auto it = prices.begin(); it != prices.end(); ++it) {
            const auto proto = *it;
            std::find_if_not(std::next(it), prices.end(), [&it](auto&& p) { return p >= *it ? (++it, true) : false; });
            res += static_cast<T>(*it - proto);
        }
        return res;
    }

    template <typename T>
    typename std::enable_if_t<std::is_arithmetic_v<T>, T>
    maxProfit(std::initializer_list<T> prices)
    {
        return maxProfit<std::initializer_list<T>&&, T>(std::forward<std::initializer_list<T>&&>(prices));
    }

    template <typename T, typename... Args>
    typename std::enable_if_t<
        std::is_arithmetic_v<std::decay_t<T>> && std::conjunction_v<std::is_same<std::decay_t<T>, std::decay_t<Args>>...>,
        T>
    maxProfit(T&& price, Args&&... prices)
    {
        return maxProfit(std::initializer_list<T> { std::forward<T>(price), std::forward<Args>(prices)... });
    }

    template <typename T, std::size_t N>
    typename std::enable_if_t<std::is_arithmetic_v<T>, T>
        maxProfit(T (&prices)[N])
    {
        return maxProfit(std::vector<T>(prices, prices + N));
    }
};

double run_time_check(std::function<void(void)> func)
{
    auto start = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> diff = end - start;
    return diff.count();
}

#include "data.h"

using Int = int64_t;

int main()
{
    std::cout << "Vector: " << run_time_check([] { Solution {}.maxProfit(std::vector<Int> { _LIST }); }) << "ms"    << std::endl;
    std::cout << "Array: " << run_time_check([] { Solution {}.maxProfit(std::array { _LIST }); }) << "ms"           << std::endl;
    std::cout << "Linked list: " << run_time_check([] { Solution {}.maxProfit(std::list<Int> { _LIST }); }) << "ms" << std::endl;
    std::cout << "Deque: " << run_time_check([] { Solution {}.maxProfit(std::deque<Int> { _LIST }); }) << "ms"      << std::endl;
    std::cout << "Initializer list: " << run_time_check([] { Solution {}.maxProfit({ _LIST }); }) << "ms"           << std::endl;
    std::cout << "Normal params: " << run_time_check([] { Solution {}.maxProfit(_LIST); }) << "ms"                  << std::endl;
    std::cout << "C array: " << run_time_check([] {
        Int arr[] { _LIST };
        Solution {}.maxProfit(arr);
    }) << "ms" << std::endl;
}