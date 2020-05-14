/*
 * @Author: Hata
 * @Date: 2020-05-14 09:20:57
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-14 09:49:51
 * @FilePath: \LeetCode\1233.cpp
 * @Description: https://leetcode-cn.com/problems/remove-sub-folders-from-the-filesystem/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string> &folder)
    {
        std::vector<std::string> res;
        std::sort(folder.begin(), folder.end());
        for (auto it = folder.begin(); it != folder.end();)
        {
            res.push_back(*it);
            it = std::find_if_not(it + 1, folder.end(), [&it](const auto &s) {
                return s.substr(0, it->length()) == *it && (s[it->length()] == '/' || s.length() <= it->length());
            });
        }
        return res;
    }
};