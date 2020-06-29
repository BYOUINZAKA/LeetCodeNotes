/*
 * @Author: Hata
 * @Date: 2020-06-22 19:14:30
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-22 19:21:51
 * @FilePath: \LeetCode\offer59.cpp
 * @Description: https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
 */
#include <bits/stdc++.h>

class MaxQueue
{
    std::queue<int> main;
    std::deque<int> supports;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return supports.empty() ? -1 : supports.front();
    }

    void push_back(int value)
    {
        while (!supports.empty())
        {
            if (value <= supports.back())
                break;
            else
                supports.pop_back();
        }
        supports.push_back(value);
        main.push(value);
    }

    int pop_front()
    {
        if (main.empty())
            return -1;
        int res = main.front();
        if (res == supports.front())
            supports.pop_front();
        main.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */