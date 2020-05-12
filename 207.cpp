/*
 * @Author: Hata
 * @Date: 2020-05-06 11:01:33
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-12 10:40:13
 * @FilePath: \LeetCode\207.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> table(numCourses);
        std::vector<int> indegrees(numCourses, 0);
        for (auto &&p : prerequisites)
        {
            ++indegrees[p.front()];
            table[p.back()].push_back(p.front());
        }
        std::queue<int> queue;
        for (int i = 0; i < numCourses; ++i)
            if (indegrees[i] == 0)
                queue.push(i);
        while (!queue.empty())
        {
            int temp = queue.front();
            queue.pop();
            --numCourses;
            for (auto &&p : table[temp])
                if (--indegrees[p] == 0)
                    queue.push(p);
        }
        return numCourses == 0;
    }
};