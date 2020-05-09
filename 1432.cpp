/*
 * @Author: Hata
 * @Date: 2020-05-06 11:45:50
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 11:46:16
 * @FilePath: \LeetCode\1432.cpp
 * @Description: 改变一个整数能得到的最大差值
 */

#include <bits/stdc++.h>
class Solution
{
public:
    int maxDiff(int num)
    {
        std::string s_num = std::to_string(num);
        int min_val = num, max_val = num;
        std::size_t flag;
        // 找第一个不是9的数全部替换为9。
        if (flag = s_num.find_first_not_of('9'), flag != std::string::npos)
        {
            max_val = std::stoi(std::regex_replace(s_num, std::regex{s_num.substr(flag, 1)}, "9"));
        }
        // 看第一位是不是1。
        if (s_num.front() == '1')
        {
            for (int i = 1; i < s_num.length(); ++i)
            {
                // 从第二位数开始查找第一个既不是0也不是1的数。
                if (s_num[i] != '0' && s_num[i] != '1')
                {
                    min_val = std::stoi(std::regex_replace(s_num, std::regex{s_num.substr(i, 1)}, "0"));
                    break;
                }
            }
        }
        // 不是1的话直接替换成1就行了。
        else
            min_val = std::stoi(std::regex_replace(s_num, std::regex{s_num.substr(0, 1)}, "1"));

        return max_val - min_val;
    }
};