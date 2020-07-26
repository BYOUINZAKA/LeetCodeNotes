/*
 * @Author: Hata
 * @Date: 2020-07-25 23:06:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 02:50:10
 * @FilePath: \LeetCode\competition\20200725\C.cpp
 * @Description:
 */
#include "leetcode.h"

class Solution {
public:
    int numSplits(string &s) {
        const int N = s.length();
        std::unordered_map<char, int> left, right;
        ++left[s[0]];
        for (int i = 1; i < N; ++i) ++right[s[i]];
        int res = 0;
        for (int i = 1; i < N; ++i) {
            if (left.size() == right.size()) {
                ++res;
            }
            ++left[s[i]];
            remove(right, s[i]);
        }
        return res;
    }

    void remove(std::unordered_map<char, int> &map, char c) {
        if (map[c] == 1)
            map.erase(c);
        else
            --map[c];
    }
};

int main() {
    string s = "aacaba";
    Solution().numSplits(s);
}