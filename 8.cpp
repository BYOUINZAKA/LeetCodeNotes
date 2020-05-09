/*
 * @Author: Hata
 * @Date: 2020-05-07 12:09:19
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 12:29:38
 * @FilePath: \LeetCode\8.cpp
 * @Description: 
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int myAtoi(const std::string &str)
    {
        if (str.empty())
            return 0;
        long long res = 0;
        bool oper = true, over = false;
        int begin = str.find_first_not_of(' ');
        if (begin == std::string::npos)
            return 0;
        if (str[begin] == '+' || str[begin] == '-')
        {
            oper = str[begin] == '+';
            ++begin;
        }
        for (; begin < str.length(); ++begin)
        {
            if (str[begin] <= '9' && str[begin] >= '0')
            {
                res = res * 10 + (str[begin] - 48);
                if (res > std::numeric_limits<int>::max())
                {
                    over = true;
                    break;
                }
            }
            else
                return oper ? res : -res;
        }
        if (over)
            return oper ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
        return oper ? res : -res;
    }
};

int main(){
    Solution s;
    std::cout << s.myAtoi("-2637816") << std::endl;
    return 0;
}