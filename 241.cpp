/*
 * @Author: Hata
 * @Date: 2020-05-10 04:52:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-10 04:52:21
 * @FilePath: \LeetCode\241.cpp
 * @Description: 
 */

#include "leetcode.h"

class Solution
{
public:
    vector<int> operands;
    vector<char> operators;
    vector<int> dp[10][10];

    vector<int> diffWaysToCompute(const string &input)
    {
        size_t start = 0;
        for (size_t i = 0; i < input.length(); i++)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                operands.push_back(stoi(input.substr(start, i - start)));
                operators.push_back(input[i]);
                start = i + 1;
            }
        }
        operands.push_back(stoi(input.substr(start, input.length() - start)));
        size_t size = operands.size();
        for (int i = 0; i < size; i++)
            dp[i][i].push_back(operands[i]);
        for (int x = 1; x < size; x++)
        {
            int i;
            for (int j = x; j < size; j++, i++)
            {
                i = j - x;
                for (int k = i; k < j; k++)
                {
                    operation(i, k, j);
                }
            }
        }
        return dp[0][size - 1];
    }

    void operation(size_t i, size_t k, size_t j)
    {
        char oper = operators[k];
        for (auto x : dp[i][k])
        {
            for (auto y : dp[k + 1][j])
            {
                switch (oper)
                {
                case '+':
                    dp[i][j].push_back(x + y);
                    break;
                case '-':
                    dp[i][j].push_back(x - y);
                    break;
                case '*':
                    dp[i][j].push_back(x * y);
                    break;
                default:
                    break;
                }
            }
        }
    }
};