/*
 * @Author: Hata
 * @Date: 2020-07-28 00:18:28
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 01:00:09
 * @FilePath: \LeetCode\295.cpp
 * @Description: https://leetcode-cn.com/problems/find-median-from-data-stream/
 */

#include <bits/stdc++.h>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : low_mid{tree.end()}, high_mid{tree.end()} {}

    void addNum(int num) {
        const int n = tree.size();
        tree.insert(num);
        if (!n) {
            low_mid = high_mid = tree.begin();
        } else if (n & 0b1) {
            if (num < *low_mid)
                --low_mid;
            else
                ++high_mid;
        } else {
            if (num > *low_mid && num < *high_mid) {
                ++low_mid;
                --high_mid;
            } else if (num >= *high_mid)
                ++low_mid;
            else
                low_mid = --high_mid;
        }
    }

    double findMedian() { return (*low_mid + *high_mid) * 0.5; }

private:
    std::multiset<int> tree;
    std::multiset<int>::iterator low_mid, high_mid;
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(3);
    q.push(2);
    q.push(1);
    std::cout << q.top();
}