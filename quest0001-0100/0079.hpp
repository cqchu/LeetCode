#ifndef __0079_H
#define __0079_H

/*******************************************
Description:
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*******************************************/

#include "../includes.hpp"

class Solution {
public:
    bool recurse(vector<vector<char>> &board, string &word,
                 vector<vector<bool>> &visited, int i, int j, int curDepth) {
        if (curDepth == word.size())
            return true;
        bool res = false;
        if (res != true && i - 1 >= 0 && visited[i - 1][j] == false &&
            board[i - 1][j] == word[curDepth]) {
            visited[i - 1][j] = true;
            res = recurse(board, word, visited, i - 1, j, curDepth + 1);
            visited[i - 1][j] = false;
        }
        if (res != true && j - 1 >= 0 && visited[i][j - 1] == false &&
            board[i][j - 1] == word[curDepth]) {
            visited[i][j - 1] = true;
            res = recurse(board, word, visited, i, j - 1, curDepth + 1);
            visited[i][j - 1] = false;
        }
        if (res != true && i + 1 < board.size() && visited[i + 1][j] == false &&
            board[i + 1][j] == word[curDepth]) {
            visited[i + 1][j] = true;
            res = recurse(board, word, visited, i + 1, j, curDepth + 1);
            visited[i + 1][j] = false;
        }
        if (res != true && j + 1 < board[0].size() &&
            visited[i][j + 1] == false && board[i][j + 1] == word[curDepth]) {
            visited[i][j + 1] = true;
            res = recurse(board, word, visited, i, j + 1, curDepth + 1);
            visited[i][j + 1] = false;
        }
        return res;
    }

    bool exist(vector<vector<char>> &board, string word) {
        if (word.size() == 0)
            return true;
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (recurse(board, word, visited, i, j, 1))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
#endif
