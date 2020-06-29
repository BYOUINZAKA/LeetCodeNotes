/*
 * @Author: Hata
 * @Date: 2020-06-28 22:55:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-28 23:13:53
 * @FilePath: \LeetCode\1117.cpp
 * @Description: https://leetcode-cn.com/problems/building-h2o/
 */
#include <bits/stdc++.h>

class H2O
{
    std::mutex m;
    std::condition_variable cv;
    int h_count, o_count;

public:
    H2O()
        : h_count{0}, o_count{0}
    {
    }

    void hydrogen(std::function<void()> releaseHydrogen)
    {
        std::unique_lock<std::mutex> lock{m};
        cv.wait(lock, [this] { return h_count < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++h_count;
        if (h_count + o_count == 3)
        {
            h_count = o_count = 0;
        }
        cv.notify_all();
    }

    void oxygen(std::function<void()> releaseOxygen)
    {
        std::unique_lock<std::mutex> lock{m};
        cv.wait(lock, [this] { return o_count < 1; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++o_count;
        if (h_count + o_count == 3)
        {
            h_count = o_count = 0;
        }
        cv.notify_all();
    }
};