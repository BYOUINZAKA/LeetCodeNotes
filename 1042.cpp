/*
 * @Author: Hata
 * @Date: 2020-05-06 10:08:52
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 10:24:22
 * @FilePath: \LeetCode\1042.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> gardenNoAdj(int N, std::vector<std::vector<int>> &paths)
    {
        std::vector<std::vector<int>> table(N);
        for (auto &&p : paths)
        {
            table[p[0] - 1].push_back(p[1] - 1);
            table[p[1] - 1].push_back(p[0] - 1);
        }
        std::vector<int> res(N, 0);
        for (int i = 0; i < N; ++i)
        {
            std::unordered_set<int> color{1, 2, 3, 4};
            for (int j = 0; j < table[i].size(); ++j)
            {
                color.erase(res[table[i][j]]);
            }
            res[i] = *color.begin();
        }
        return res;
    }
};