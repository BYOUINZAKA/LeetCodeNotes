/*
 * @Author: Hata
 * @Date: 2020-05-19 18:22:24
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-19 18:51:14
 * @FilePath: \LeetCode\831.cpp
 * @Description: https://leetcode-cn.com/problems/masking-personal-information/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using rIter = std::string::const_reverse_iterator;
    std::string maskPII(std::string &S)
    {
        auto at = std::find(S.begin(), S.end(), '@');
        if (at != S.end())
        {
            S.replace(S.begin() + 1, at - 1, "*****");
            std::for_each(
                S.begin(), S.end(), [](auto &c) { c = tolower(c); });
        }
        else
        { //如果是电话，记录 数字的数量cnt   记录 最后四个数字到queue
            std::string res;
            int cnt = 0;
            std::queue<char> q;
            for (int i = 0; i < S.size(); i++)
            {
                if (S[i] >= '0' && S[i] <= '9')
                {
                    cnt++;
                    q.push(S[i]);
                    if (q.size() > 4)
                    {
                        q.pop();
                    }
                }
            }
            std::string ss(4, ' ');
            int k = 0;
            while (!q.empty())
            {
                ss[k] = q.front();
                q.pop();
                k++;
            }
            if (cnt > 10)
            {
                if (cnt == 11)
                    res = "+*-***-***-" + ss;
                if (cnt == 12)
                    res = "+**-***-***-" + ss;
                if (cnt == 13)
                    res = "+***-***-***-" + ss;
            }
            else
            {
                res = "***-***-" + ss;
            }
            return res;
        }
        return S;
    }
};