#ifndef __0037_H
#define __0037_H

/************************************************
Description:
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.

Note:
    The given board contain only digits 1-9 and the character '.'.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.
************************************************/

#include "../includes.hpp"

class Solution {
public:
    set<char> getChoices(const vector<vector<char>>& board, int row, int col) {
        set<char> sc = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        if (board[row][col] != '.') {
            sc.clear();
            return sc;
        }
        
        for (int i=0; i<9; i++) {
            if (board[i][col] != '.') {
                sc.erase(board[i][col]);
            }
            if (board[row][i] != '.') {
                sc.erase(board[row][i]);
            }
        }
        int gridR = row / 3, gridC = col / 3; 
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if(board[gridR*3+i][gridC*3+j] != '.') {
                    sc.erase(board[gridR*3+i][gridC*3+j]);
                }
            }
        }

        return sc;
    }
    
    void initChoices(const vector<vector<char>>& board, vector<vector<set<char>>>& choices) {
        choices.clear();
        for (int r=0; r<9; r++) {
            vector<set<char>> vsc;
            for (int c=0; c<9; c++) {
                vsc.push_back(getChoices(board, r, c)); // for each point, find the potential solution
            }
            choices.push_back(vsc);
        }
    }
    
    bool nextBlank(const vector<vector<set<char>>>& choices, int &row, int &col) {
        int min = 100;
        row = -1;
        col = -1;
        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++) {
                if (choices[r][c].size()!=0 && choices[r][c].size() < min) {
                    row = r;
                    col = c;
                    min = choices[r][c].size();
                }
            }
        }
        if (row == -1 || col == -1)
            return false;
        else
            return true;
    }
    
    bool checkBoard(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            set<char> sc;
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.')
                    return false;
                sc.insert(board[i][j]);
            }
            if (sc.size() != 9)
                return false;
        }
        
        for (int i=0; i<9; i++) {
            set<char> sc;
            for (int j=0; j<9; j++) {
                if (board[j][i] == '.')
                    return false;
                sc.insert(board[j][i]);
            }
            if (sc.size() != 9)
                return false;
        }
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                set<char> sc;
                for (int r=0; r<3; r++) {
                    for (int c=0; c<3; c++) {
                        if(board[i*3+r][j*3+c] == '.')
                            return false;
                        sc.insert(board[i*3+r][j*3+c]);
                    } 
                }
                if (sc.size() != 9)
                    return false;
            }     
        }

        return true;
    }
    
    vector<vector<char>> recurse(vector<vector<char>> board) {
        if (checkBoard(board))
            return board;
        vector<vector<set<char>>> choices;
        initChoices(board, choices);
        int br, bc;
        if(nextBlank(choices, br, bc)) {
            for(auto ch: choices[br][bc]) {
                board[br][bc] = ch;
                vector<vector<char>> tboard = recurse(board);
                if (tboard.size() != 0)
                    return tboard;
            }
        }
        board.clear();
        return board;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        board = recurse(board);
    }
};

#endif

