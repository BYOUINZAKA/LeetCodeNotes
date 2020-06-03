/*
 * @Author: Hata
 * @Date: 2020-06-04 01:45:50
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 01:49:06
 * @FilePath: \LeetCode\341.cpp
 * @Description: https://leetcode-cn.com/problems/flatten-nested-list-iterator/
 */
#include "leetcode.h"

class NestedIterator
{
    std::stack<NestedInteger> stack;

public:
    NestedIterator(vector<NestedInteger> &nestedList) : stack{}
    {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it)
            stack.push(*it);
    }

    int next()
    {
        auto i = stack.top();
        stack.pop();
        return i.getInteger();
    }

    bool hasNext()
    {
        while (!stack.empty())
        {
            auto value = stack.top();
            if (value.isInteger())
                return true;
            stack.pop();
            auto list = value.getList();
            for (auto it = list.rbegin(); it != list.rend(); ++it)
                stack.push(*it);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */