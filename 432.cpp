/*
 * @Author: Hata
 * @Date: 2020-06-07 22:43:36
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-08 01:45:54
 * @FilePath: \LeetCode\432.cpp
 * @Description: https://leetcode-cn.com/problems/all-oone-data-structure/
 */
#include <bits/stdc++.h>

class AllOne
{
public:
    using Set = std::unordered_set<std::string>;
    using Iter = std::list<std::pair<int, Set>>::iterator;
    friend std::string to_string(const AllOne &);

private:
    std::list<std::pair<int, Set>> countList;
    std::unordered_map<std::string, Iter> table;

public:
    /** Initialize your data structure here. */
    AllOne()
    {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(const std::string &key)
    {
        if (table.find(key) == table.end())
        {
            if (!countList.empty() && countList.front().first == 1)
                countList.front().second.insert(key);
            else
                countList.emplace_front(1, Set{key});
            table[key] = countList.begin();
        }
        else
        {
            insert(table.at(key), key, 1);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(const std::string &key)
    {
        if (table.find(key) != table.end())
            insert(table.at(key), key, -1);
    }

    /** Returns one of the keys with maximal value. */
    std::string getMaxKey()
    {
        if (countList.empty())
            return "";
        return *(countList.back().second.cbegin());
    }

    /** Returns one of the keys with Minimal value. */
    std::string getMinKey()
    {
        if (countList.empty())
            return "";
        return *(countList.front().second.cbegin());
    }

private:
    Iter remove(Iter hint, const std::string &key)
    {
        hint->second.erase(key);
        if (hint->second.empty())
            return countList.erase(hint);
        else
            return hint;
    }

    void insert(Iter hint, const std::string &key, int dis)
    {
        int value = hint->first + dis;
        if (value == 0)
        {
            table.erase(key);
            remove(hint, key);
            return;
        }

        auto target = std::next(hint, dis);
        auto end = dis > 0 ? countList.rbegin().base() : countList.begin();
        auto index = dis > 0 ? target : hint;
        if (hint != end && target->first == value)
        {
            target->second.insert(key);
            table[key] = target;
        }
        else
        {
            table[key] = countList.emplace(index, value, Set{key});
        }
        remove(hint, key);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

std::string to_string(const AllOne &allone)
{
    std::string res{"{"};
    for (auto &&pair : allone.countList)
    {
        // res.push_back('}');
        for (auto &&s : pair.second)
        {
            res.push_back('\"');
            res.append(s);
            res.append("\": ");
            res.append(std::to_string(pair.first));
            res.append(", ");
        }
    }
    res.pop_back();
    res.pop_back();
    res.push_back('}');
    return res;
}

int main()
{
    AllOne allone;
    allone.inc("hello");
    allone.inc("hello");
    allone.inc("hello");
    allone.inc("yellow");
    allone.inc("yellow");
    allone.inc("red");
    allone.dec("yellow");
    allone.inc("red");
    allone.inc("fqafq");
    allone.inc("red");
    std::cout << to_string(allone) << std::endl;
}