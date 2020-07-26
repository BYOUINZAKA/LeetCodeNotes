/*
 * @Author: Hata
 * @Date: 2020-07-07 19:42:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-25 23:01:54
 * @FilePath: \LeetCode\1371.cpp
 * @Description: https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 */
#include <bits/stdc++.h>

class Solution
{
    constexpr static const int8_t mapping[] =
        {0b00001, 0, 0, 0, 0b00010, 0, 0, 0, 0b00100, 0, 0, 0, 0, 0, 0b01000, 0, 0, 0, 0, 0, 0b10000, 0, 0, 0, 0, 0};

public:
    int findTheLongestSubstring(std::string_view &&s)
    {
        int res = 0;

        std::array<std::optional<int>, 0b100000> table = {-1};
        int32_t const k_length = s.length();
        int8_t status = 0;

        for (int i = 0; i < k_length; ++i)
        {
            status ^= mapping[s[i] - 'a'];
            if (table[status].has_value())
                res = std::max(res, i - table[status].value());
            else
                table[status] = i;
        }

        return res;
    }
};

int main()
{
    using namespace std::string_literals;
    std::cout << Solution{}.findTheLongestSubstring("eleetminicoworoep"s) << std::endl;
    std::cout << Solution{}.findTheLongestSubstring("qnplnlarrtztkotazhufrsfczrzibvccao \
    ayyihidztfljcffiqfviuwjowkppdajmknzgidixqgtnahamebxfowqvnrhuzwqohquamvszkvunbxjegbj \
    ccjjxfnsiearbsgsofywtqbmgldgsvnsgpdvmjqpaktmjafgkzszekngivdmrlvrpyrhcxbceffrgiyktqi \
    lkkdjhtywpesrydkbncmzeekdtszmcsrhsciljsrdoidzbjatvacndzbghzsnfdofvhfxdnmzrjriwpkdgu \
    kbaazjxtkomkmccktodig"s);
}