/*
 * @Author: Hata
 * @Date: 2020-05-07 14:20:38
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-11 19:38:00
 * @FilePath: \LeetCode\leetcode.h
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;

inline double runTimeCheck(std::function<void(void)> func)
{
    auto start = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> diff = end - start;
    return diff.count();
}

template <class Data, typename T = typename Data::value_type>
std::vector<Data> dataGenerator(
    size_t count, std::initializer_list<int> shape, bool any_shape = true)
{
    std::vector<Data> result;
    for (int i = 0; i < count; ++i) { 
        
    }
    return result;
}

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const { }
};
