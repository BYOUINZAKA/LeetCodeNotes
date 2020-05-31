/*
 * @Author: Hata
 * @Date: 2020-05-30 17:40:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-30 20:16:55
 * @FilePath: \LeetCode\468.cpp
 * @Description: https://leetcode-cn.com/problems/validate-ip-address/
 */

#include <string>
#include <vector>
#include <string_view>
#include <algorithm>

std::vector<std::string_view>
splitSV(std::string_view strv, std::string_view delims = " ")
{
    std::vector<std::string_view> output;
    size_t first = 0;
    while (first < strv.size())
    {
        const auto second = strv.find_first_of(delims, first);
        if (first != second)
            output.emplace_back(strv.substr(first, second - first));
        else
            output.emplace_back("");
        if (second == std::string_view::npos)
            break;
        first = second + 1;
    }
    return output;
}

class Solution
{
public:
    std::string validIPAddress(std::string &IP)
    {
        if (!std::isxdigit(IP.front()) || !std::isxdigit(IP.back()))
            return "Neither";
        auto v4 = splitSV(IP, ".");
        if (v4.size() == 4)
            return std::all_of(v4.begin(), v4.end(), [&](auto &&ip) { return checkIPv4(ip); }) ? "IPv4" : "Neither";
        else
        {
            auto v6 = splitSV(IP, ":");
            if (v6.size() == 8)
                return std::all_of(v6.begin(), v6.end(), [&](auto &&ip) { return checkIPv6(ip); }) ? "IPv6" : "Neither";
            else
                return "Neither";
        }
        return "Neither";
    }

    bool checkIPv4(std::string_view ip)
    {
        if (ip.size() > 3 || ip.size() == 0)
            return false;
        else if (ip.front() == '0')
            return ip.size() == 1;
        int i = 0;
        for (auto &&c : ip)
            if (isdigit(c))
                i = i * 10 + (c - '0');
            else
                return false;
        return i <= 255;
    }

    bool checkIPv6(std::string_view ip)
    {
        if (ip.size() > 4 || ip.size() == 0)
            return false;
        return std::all_of(ip.begin(), ip.end(), [](auto &&c) { return std::isxdigit(c); });
    }
};