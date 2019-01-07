//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/sudoku-solver/
    Write a program to solve a Sudoku puzzle by filling the empty cells.
 */

struct Point {
    int i_ = 0;
    int j_ = 0;

    Point(int i, int j):i_(i),j_(j) {

    }
};

class Solution {
public:

    vector<bitset<9>> sudoku_bitmap = vector<bitset<9>>(27);
    vector<Point> empty_points;

    void solveSudoku(vector<vector<char>>& board) {

        uint8_t value = 0;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    empty_points.push_back(Point(i, j));
                    continue;
                }
                //from 0-8
                value = static_cast<uint8_t>(board[i][j] - '0' - 1);
                setSudokuValue(i, j, value);
            }
        }

        dfs(board, 0);
    }

    bool dfs(vector<vector<char>>& board, int step) {
        if (step == empty_points.size() ) {
            return true;
        }

        int i = empty_points[step].i_;
        int j = empty_points[step].j_;

        for (int num = 0; num < 9; num++) {
            if (isSudokuValid(i, j, num)) {
                board[i][j] = static_cast<char>(num + '0' + 1);

                setSudokuValue(i, j, num);
                if (dfs(board, step + 1)) {
                    return true;
                }
                unsetSudokuValue(i, j, num);
                board[i][j] = '.';
            }
        }


        return false;
    }

    inline bool isSudokuValid(int i, int j, uint8_t value) {
        //row
        if (sudoku_bitmap[i][value]) { return false; }
        //column
        if (sudoku_bitmap[j + 9][value]) { return false; }
        //sub_box
        auto sub_box_id = (i / 3) + (j / 3) * 3 + 18;
        if (sudoku_bitmap[sub_box_id][value]) { return false; }

        return true;
    }

    inline void setSudokuValue(int i, int j, uint8_t value) {
        //row
        sudoku_bitmap[i].set(value);
        //column
        sudoku_bitmap[j + 9].set(value);
        //sub_box
        auto sub_box_id = (i / 3) + (j / 3) * 3 + 18;
        sudoku_bitmap[sub_box_id].set(value);
    }

    inline void unsetSudokuValue(int i, int j, uint8_t value) {
        //row
        sudoku_bitmap[i].set(value, false);
        //column
        sudoku_bitmap[j + 9].set(value, false);
        //sub_box
        auto sub_box_id = (i / 3) + (j / 3) * 3 + 18;
        sudoku_bitmap[sub_box_id].set(value, false);
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();


class Checker {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<bitset<9>> bitmap(27);
        uint8_t value = 0;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') { continue; }

                value = static_cast<uint8_t>(board[i][j] - '0' - 1);

                auto &row_bitmap = bitmap[i];
                if (!setSudokuValue(row_bitmap, value)) {
                    return false;
                }

                auto &column_bitmap = bitmap[j + 9];
                if (!setSudokuValue(column_bitmap, value)) {
                    return false;
                }

                auto sub_box_id = (i / 3) + (j / 3) * 3 + 18;
                auto &box_bitmap = bitmap[sub_box_id];
                if (!setSudokuValue(box_bitmap, value)) {
                    return false;
                }
            }
        }

        return true;
    }

    inline bool setSudokuValue(bitset<9>& sudoku_bitset, uint8_t value) {
        if (sudoku_bitset[value]) {
            return false;
        } else {
            sudoku_bitset.set(value);
            return true;
        }
    }
};

TEST_CASE("SudokuSolver") {
    vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    auto res = Checker().isValidSudoku(board);
    REQUIRE( res);
    Solution().solveSudoku(board);
    res = Checker().isValidSudoku(board);
    REQUIRE( res);

    board = {
            {'.','.','4','.','.','.','6','3','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'5','.','.','.','.','.','.','9','.'},
            {'.','.','.','5','6','.','.','.','.'},
            {'4','.','3','.','.','.','.','.','1'},
            {'.','.','.','7','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'}
    };
    Solution().solveSudoku(board);
    Checker().isValidSudoku(board);
    REQUIRE( res );
}

