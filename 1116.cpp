/*
 * @Author: Hata
 * @Date: 2020-07-28 01:05:07
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 01:45:57
 * @FilePath: \LeetCode\1116.cpp
 * @Description: https://leetcode-cn.com/problems/print-zero-even-odd/
 */
#include <bits/stdc++.h>

class ZeroEvenOdd {
private:
    int n;
    int count;
    std::mutex mutex;
    std::condition_variable cv0, cv1;

    constexpr bool finished() const { return count <= n; }

public:
    ZeroEvenOdd(int _n) : n{_n}, count{1} {}

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        while (finished()) {
            std::unique_lock<std::mutex> l(mutex);
            printNumber(0);
            cv1.notify_all();
            cv0.wait(l);
        }
        cv1.notify_all();
    }

    void even(std::function<void(int)> printNumber) {
        while (finished()) {
            std::unique_lock<std::mutex> l(mutex);
            cv1.wait(l, [this] { return count % 2 == 0; });
            if (finished()) printNumber(count);
            ++count;
            cv0.notify_one();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        while (finished()) {
            std::unique_lock<std::mutex> l(mutex);
            cv1.wait(l, [this] { return count % 2 != 0; });
            if (finished()) printNumber(count);
            ++count;
            cv0.notify_one();
        }
    }
};

int main() {
    ZeroEvenOdd qus{13};

    auto print_number = [](int i) { std::cout << i << ", "; };

    std::thread th_0{&ZeroEvenOdd::zero, &qus, print_number};
    std::thread th_even{&ZeroEvenOdd::even, &qus, print_number};
    std::thread th_odd{&ZeroEvenOdd::odd, &qus, print_number};

    th_0.join();
    th_even.join();
    th_odd.join();
}