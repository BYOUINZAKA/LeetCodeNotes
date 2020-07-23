/*
 * @Author: Hata
 * @Date: 2020-07-15 18:47:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-20 22:21:47
 * @FilePath: \LeetCode\37.cpp
 * @Description: https://leetcode-cn.com/problems/sudoku-solver/
 */
#include <bits/stdc++.h>

#include "tools.h"

class Solution {
public:
    enum { NumCount = 9, RowsCount = 9, ColsCount = 9 };
    constexpr static const char EmptyGrid = '.';

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        initFlags(board);
        backTrack(board, 0, 0);

#ifdef __LCTOOLS_TOOLS_
        std::cout << lctools::Formatter::ToString(board) << std::endl;
#endif
    }

private:
    bool backTrack(std::vector<std::vector<char>>& board, int i, int j) {
        if (!enable(board, i, j)) return nextTrack(board, i, j);

        auto &&block = blocks_flag[blockIndex(i, j)], &&row = rows_flag[i], &&col = cols_flag[j];
        auto for_check = ~(row | col | block);

        for (int val = 0; val < NumCount; ++val) {
            if (for_check[val]) {
                row[val] = col[val] = block[val] = true;
                board[i][j] = trans(val);

                if (nextTrack(board, i, j)) return true;

                board[i][j] = EmptyGrid;
                row[val] = col[val] = block[val] = false;
            }
        }
        return false;
    }

    bool nextTrack(std::vector<std::vector<char>>& board, int i, int j) {
        if (++j == ColsCount) {
            j = 0;
            if (++i == RowsCount) return true;
        }
        return backTrack(board, i, j);
    }

    void initFlags(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < RowsCount; ++i) {
            for (int j = 0; j < ColsCount; ++j) {
                if (!enable(board, i, j)) {
                    auto val = trans(board[i][j]);
                    rows_flag[i].set(val);
                    cols_flag[j].set(val);
                    blocks_flag[blockIndex(i, j)].set(val);
                }
            }
        }
    }

    inline bool enable(const std::vector<std::vector<char>>& board, const int i,
                       const int j) const {
        return board[i][j] == EmptyGrid;
    }

    constexpr int blockIndex(const int i, const int j) const { return (i / 3) * 3 + j / 3; }

    constexpr int trans(const char c) const { return c - '1'; }
    constexpr char trans(const int val) const { return val + '1'; }

private:
    std::bitset<NumCount> rows_flag[RowsCount];
    std::bitset<NumCount> cols_flag[ColsCount];
    std::bitset<NumCount> blocks_flag[NumCount];
};

int main() {
    std::vector<std::vector<char>> matrix{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution{}.solveSudoku(matrix);
}