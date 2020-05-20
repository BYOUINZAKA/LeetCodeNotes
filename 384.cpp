/*
 * @Author: Hata
 * @Date: 2020-05-20 16:54:22
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 16:58:05
 * @FilePath: \LeetCode\384.cpp
 * @Description: https://leetcode-cn.com/problems/shuffle-an-array/
 */
#include <bits/stdc++.h>

class Solution
{
    std::vector<int> prime, shuff;
    std::mt19937 g;

public:
    Solution(std::vector<int> &nums) : prime{nums}, shuff{nums}, g{std::random_device{}()}
    {
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset()
    {
        return prime;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle()
    {
        std::shuffle(shuff.begin(), shuff.end(), g);
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */