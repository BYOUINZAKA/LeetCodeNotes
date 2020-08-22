#include "leetcode.h"

class Solution {
public:
    int minOperations(int n) {
        if (n & 1) {
            return (0 + n - 1) * ((n + 1) / 2) / 2;
        } else {
            return (1 + n - 1) * (n / 2) / 2;
        }
    }
};