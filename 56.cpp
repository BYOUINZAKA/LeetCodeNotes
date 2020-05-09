/*
 * @Author: Hata
 * @Date: 2020-05-10 04:51:29
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-10 04:51:38
 * @FilePath: \LeetCode\56.cpp
 * @Description: 
 */
#include "leetcode.h"

class Solution
{
public:
    struct set
    {
        int v;
        int k;
        set(const int &_v, const int &_k) : v(_v), k(_k) {}
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        vector<set> range;
        for (auto &i : intervals)
        {
            range.push_back(set(i[0], 1));
            range.push_back(set(i[1], -1));
        }
        sort(range.begin(), range.end(), [](const set &a, const set &b) {
            if (a.v != b.v)
                return a.v < b.v;
            else
                return a.k > b.k;
        });
        for (auto i = range.begin(); i != range.end(); i++)
        {
            int count = 0;
            auto end_ptr = i;
            for (; end_ptr != range.end(); end_ptr++)
            {
                count += end_ptr->k;
                if (count == 0)
                    break;
            }
            result.push_back(vector<int>{i->v, end_ptr->v});
            i = end_ptr;
        }
        return result;
    }
};