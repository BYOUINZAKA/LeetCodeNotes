/*
 * @Author: Hata
 * @Date: 2020-05-31 16:08:18
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-31 16:53:39
 * @FilePath: \LeetCode\1020.cpp
 * @Description: https://leetcode-cn.com/problems/number-of-enclaves/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> A;
    int numEnclaves(std::vector<std::vector<int>> &A)
    {
        this->A = A;
        int m = A.size();
        int n = A[0].size();
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(0, i);
            dfs(m - 1, i);
        }
        int res = 0;
        for (auto &&i : this->A)
            for (auto &&j : i)
                res += j == 1;
        return res;
    }

    void dfs(int x, int y)
    {
        if (A[x][y] == 0)
            return;
        A[x][y] = 2;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && x1 < A.size() && y1 >= 0 && y1 < A[0].size() && A[x1][y1] == 1)
                dfs(x1, y1);
        }
    }
};