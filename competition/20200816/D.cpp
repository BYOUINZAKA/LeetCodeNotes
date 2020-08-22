#include "leetcode.h"

std::unordered_map<int, int> table{{1, 1}, {2, 2}};

class Solution {
public:
    int minDays(int n) {
        if (table.find(n) != table.end()) return table[n];
        int res = 0x3f3f3f;

        if ((n - 1) % 3 == 0 || (n - 1) % 2 == 0) res = std::min(res, minDays(n - 1));
        if (n % 2 == 0) res = std::min(res, minDays(n / 2));
        if (n % 3 == 0) res = std::min(res, minDays(n / 3));

        table[n] = ++res;
        return res;
    }
};