/*
 * @Author: Hata
 * @Date: 2020-07-11 17:39:15
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-13 00:21:34
 * @FilePath: \LeetCode\1388.cpp
 * @Description: https://leetcode-cn.com/problems/pizza-with-3n-slices/
 */

#include <bits/stdc++.h>

template <template <class> class C = std::vector>
class Solution {
    struct Node {
        using Container = C<Node>;
        using Iter = typename Container::iterator;

        int val;
        bool takeable;
        Iter left, right;

        Node(int _val) : val{_val}, takeable{true} {}

        struct Compare {
            inline bool operator()(Iter lhs, Iter rhs) const { return lhs->val < rhs->val; }
        };
    };

public:
    template <class List>
    int maxSizeSlices(List&& slices) {
        using Container = typename Node::Container;
        using Iterator = typename Node::Iter;
        using Compare = typename Node::Compare;

        const int max_count = slices.size() / 3.0;
        int res = 0;

        Container main_list(slices.begin(), slices.end());
        std::priority_queue<Iterator, std::deque<Iterator>, Compare> max_queue;

        for (auto it = main_list.begin(); it != main_list.end(); ++it) {
            it->left = main_list.begin() == it ? std::prev(main_list.end()) : std::prev(it);
            it->right = std::prev(main_list.end()) == it ? main_list.begin() : std::next(it);
            max_queue.push(it);
        }

        for (int count = 0; count < max_count;) {
            auto node = max_queue.top();
            max_queue.pop();
            if (node->takeable) {
                int left = node->left->val, right = node->right->val;
                ++count;
                res += node->val;

                deleteNode(node->left);
                deleteNode(node->right);
                node->val = left + right - node->val;
                max_queue.push(node);
            }
        }
        return res;
    }

private:
    template <class Iter>
    constexpr void deleteNode(Iter node) {
        node->takeable = false;
        node->left->right = node->right;
        node->right->left = node->left;
    }
};