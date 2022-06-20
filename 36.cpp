
#include "includes.h"

/**
 * @brief Leetcode Problem 36. Valid Sudoku
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition. Note:
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable. Only the filled cells need to be validated according to the
 * mentioned rules.
 *
 * @see https://leetcode.com/problems/valid-sudoku/
 * @date 6/15/2022
 */

class Solution {
 public:
  // Time Complexity: O(81)
  // Space Complexity: O(81)
  bool isValidSudoku(vector<vector<char>>& board) {
    // check rows, columns, and diaganols for duplicates using a set
    for (int i = 0; i < 9; i++) {
      unordered_set<char> rows;
      unordered_set<char> cols;
      unordered_set<char> diag;
      for (int j = 0; j < 9; j++) {
        int x = i / 3 * 3 + j / 3;
        int y = i % 3 * 3 + j % 3;
        if (board[i][j] != '.' && !rows.insert(board[i][j]).second)
          return false;
        if (board[j][i] != '.' && !cols.insert(board[j][i]).second)
          return false;
        if (board[x][y] != '.' && !diag.insert(board[x][y]).second)
          return false;
      }
    }

    return true;
  }
};