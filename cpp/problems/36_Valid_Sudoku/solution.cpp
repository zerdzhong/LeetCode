//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */

class Solution {
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

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

TEST_CASE("ValidSudoku") {
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
    auto res = Solution().isValidSudoku(board);
    REQUIRE( res);

    board = {
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    res = Solution().isValidSudoku(board);
    REQUIRE( !res );


    board = {
            {'.','.','4','.','.','.','6','3','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'5','.','.','.','.','.','.','9','.'},
            {'.','.','.','5','6','.','.','.','.'},
            {'4','.','3','.','.','.','.','.','1'},
            {'.','.','.','7','.','.','.','.','.'},
            {'.','.','.','5','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'}
    };
    res = Solution().isValidSudoku(board);
    REQUIRE( !res );
}

