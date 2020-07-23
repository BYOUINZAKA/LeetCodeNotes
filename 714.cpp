/*
 * @Author: Hata
 * @Date: 2020-07-23 16:04:14
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 16:10:07
 * @FilePath: \LeetCode\714.cpp
 * @Description:
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices, int fee) {
        int cash = 0, hold = -prices.front() - fee;
        for (int i = 1; i < prices.size(); ++i) {
            cash = std::max(cash, hold + prices[i]);
            hold = std::max(hold, cash - prices[i] - fee);
        }
        return cash;
    }
};