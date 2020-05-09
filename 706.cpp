/*
 * @Author: Hata
 * @Date: 2020-05-09 12:47:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-09 13:08:22
 * @FilePath: \LeetCode\706.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class MyHashMap
{
public:
    constexpr static const std::size_t size = 6151;

    /** Initialize your data structure here. */
    MyHashMap() : hash_table{}
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        auto &hash = hash_table[key % size];
        for (auto &&pair : hash)
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        hash.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        // int hash = key % size;
        auto &hash = hash_table[key % size];
        for (auto &&pair : hash)
        {
            if (pair.first == key)
                return pair.second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        auto &hash = hash_table[key % size];
        auto iter = hash.begin();
        while (iter != hash.end())
        {
            if (iter->first == key)
            {
                iter = hash.erase(iter);
                return;
            }
            else
                ++iter;
        }
    }

private:
    std::array<std::vector<std::pair<int, int>>, size> hash_table;
};