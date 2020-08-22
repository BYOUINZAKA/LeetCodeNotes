/*
 * @Author: Hata
 * @Date: 2020-08-21 21:58:24
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-21 22:33:33
 * @FilePath: \LeetCode\146.cpp
 * @Description: https://leetcode-cn.com/problems/lru-cache/
 */
#include <bits/stdc++.h>

class LRUCache {
private:
    using List = std::list<std::pair<int, int>>;

public:
    LRUCache(int capacity) { _capacity = capacity; }

    int get(int key) {
        int value = -1;
        auto it = _table.find(key);

        if (it != _table.end()) value = refresh(it);

        return value;
    }

    void put(int key, int value) {
        auto it = _table.find(key);

        if (it != _table.end()) {
            it->second->second = value;
            value = refresh(it);
        } else {
            _table.emplace(key, _priority_list.emplace(_priority_list.end(), key, value));

            if (_priority_list.size() > _capacity) {
                _table.erase(_priority_list.front().first);
                _priority_list.pop_front();
            }
        }
    }

private:
    int _capacity;
    List _priority_list;
    std::unordered_map<int, List::iterator> _table;

private:
    template <typename Iter>
    int refresh(Iter &&it) {
        auto old = it->second;
        auto key = old->first, value = old->second;

        _priority_list.erase(old);
        it->second = _priority_list.emplace(_priority_list.end(), key, value);

        return value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */