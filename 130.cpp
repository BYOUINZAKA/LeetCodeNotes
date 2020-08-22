/*
 * @Author: Hata
 * @Date: 2020-08-11 15:23:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-11 16:08:48
 * @FilePath: \LeetCode\130.cpp
 * @Description: https://leetcode-cn.com/problems/surrounded-regions/
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (0 == rows) return;
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' ||
            board[i][j] == '#') {
            return;
        }
        board[i][j] = '#';  //被包围的 和没有被包围的区分
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};