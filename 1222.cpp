/*
 * @Author: Hata
 * @Date: 2020-05-11 11:42:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 12:14:47
 * @FilePath: \LeetCode\1222.cpp
 * @Description: https://leetcode-cn.com/problems/queens-that-can-attack-the-king/
 */

#include <bits/stdc++.h>

template <>
struct std::hash<std::vector<int>>
{
    size_t operator()(const std::vector<int> &p) const noexcept
    {
        std::hash<int> hasher;
        size_t seed = 0;
        seed ^= hasher(p.front()) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hasher(p.back()) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> queensAttacktheKing(std::vector<std::vector<int>> &queens, std::vector<int> &king)
    {
        std::vector<std::vector<int>> result;
        std::unordered_set<std::vector<int>> queen_set;
        int decay[][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

        for (auto &&p : queens)
            queen_set.insert(p);

        for (auto &&d : decay)
        {
            if (result.size() == queens.size())
                return result;
            for (int x = king.front(), y = king.back(); x >= 0 && x < 8 && y >= 0 && y < 8; x += d[0], y += d[1])
            {
                std::vector<int> p{x, y};
                if (queen_set.find(p) != queen_set.end())
                {
                    result.push_back(p);
                    break;
                }
            }
        }

        return result;
    }
};