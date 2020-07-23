/*
 * @Author: Hata
 * @Date: 2020-07-01 14:00:24
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-01 15:03:12
 * @FilePath: \LeetCode\855.cpp
 * @Description: https://leetcode-cn.com/problems/exam-room/
 */
#include <bits/stdc++.h>

class ExamRoom
{
public:
    using Table = std::list<int>;
    using Iter = Table::iterator;

private:
    int size;
    Table table;
    std::unordered_map<int, Iter> map;

public:
    ExamRoom(int N) : size(N)
    {
    }

    int seat()
    {
        int insert_val = 0;
        auto insert_pos = table.begin();
        if (!table.empty())
        {
            int max_dis = table.front();
            for (auto it = std::next(table.begin()); it != table.end(); ++it)
            {
                int dis = (*it - *std::prev(it)) / 2.0;
                if (dis > max_dis)
                {
                    max_dis = dis;
                    insert_pos = it;
                    insert_val = *std::prev(it) + dis;
                }
            }
            int back_dis = size - 1 - table.back();
            if (back_dis > max_dis)
            {
                max_dis = back_dis;
                insert_pos = table.end();
                insert_val = size - 1;
            }
        }

        map[insert_val] = table.insert(insert_pos, insert_val);

        return insert_val;
    }

    void leave(int p)
    {
        table.erase(map[p]);
        map.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */