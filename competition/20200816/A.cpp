#include "leetcode.h"

class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        int count = (arr[0] & 1);
        for (int i = 1; i < arr.size(); ++i) {
            if ((arr[i] & 1) == 1) {
                if ((arr[i - 1] & 1) == 1) ++count;
                if (count == 3) return true;
            } else {
                count = 0;
            }
        }
        return false;
    }
};