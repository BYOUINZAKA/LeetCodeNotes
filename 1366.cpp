/*
 * @Author: Hata
 * @Date: 2020-07-31 12:59:28
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-31 13:42:59
 * @FilePath: \LeetCode\1366.cpp
 * @Description: https://leetcode-cn.com/problems/rank-teams-by-votes/
 */

#include <bits/stdc++.h>
#include "tools.h"

class Solution {
public:
    std::string rankTeams(std::vector<std::string>& votes) {
        using ranking = std::array<int, 27>;
        const int kLength = votes.front().length();

        std::vector<ranking> table(26, ranking{0});
        std::string res;

        for (auto&& s : votes) {
            for (int i = 0; i < kLength; ++i) {
                ++table[toIndex(s[i])][i];
            }
        }

        for (int i = 0; i < 26; ++i) {
            table[i].back() = 26 - i;
        }

        std::sort(table.begin(), table.end(), std::greater<ranking>{});

        for (int i = 0; i < kLength; ++i) {
            res.push_back(char(91 - table[i].back()));
        }

        return res;
    }

private:
    constexpr int toIndex(char c) const { return c - 'A'; }
};

int main() {
    std::vector<std::string> qus{"ABC", "ACB", "ABC", "ACB", "ACB"};

    Solution{}.rankTeams(qus);
}