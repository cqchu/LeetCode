#ifndef __0221_H
#define __0221_H

/*****************************************************
Description:
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing
only 1's and return its area.

Example 1:
Input: matrix =
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int maximalSquare2D(vector<vector<char>> &matrix) {
        size_t rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        size_t cols = matrix[0].size();
        if (cols == 0) {
            return 0;
        }

        auto valid = [](char c) -> bool { return c == '1'; };

        std::vector<std::vector<int>> edge_dp(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> row_dp(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> col_dp(rows, std::vector<int>(cols, 0));
        int max_edge = 0;

        for (size_t i = 0; i < rows; ++i) {
            if (valid(matrix[i][0])) {
                max_edge = 1;
                edge_dp[i][0] = 1;
                row_dp[i][0] = 1;
                col_dp[i][0] = i == 0 ? 1 : col_dp[i - 1][0] + 1;
            } else {
                edge_dp[i][0] = 0;
                row_dp[i][0] = 0;
                col_dp[i][0] = 0;
            }
        }

        for (size_t i = 0; i < cols; ++i) {
            if (valid(matrix[0][i])) {
                max_edge = 1;
                edge_dp[0][i] = 1;
                row_dp[0][i] = i == 0 ? 1 : row_dp[0][i - 1] + 1;
                col_dp[0][i] = 1;
            } else {
                edge_dp[0][i] = 0;
                row_dp[0][i] = 0;
                col_dp[0][i] = 0;
            }
        }

        for (size_t row = 1; row < rows; ++row) {
            for (size_t col = 1; col < cols; ++col) {
                if (valid(matrix[row][col])) {
                    row_dp[row][col] = row_dp[row][col - 1] + 1;
                    col_dp[row][col] = col_dp[row - 1][col] + 1;

                    if (row_dp[row][col] > edge_dp[row - 1][col - 1] &&
                        col_dp[row][col] > edge_dp[row - 1][col - 1]) {
                        edge_dp[row][col] = edge_dp[row - 1][col - 1] + 1;
                    } else {
                        edge_dp[row][col] =
                            std::min(row_dp[row][col], col_dp[row][col]);
                    }
                    max_edge = std::max(edge_dp[row][col], max_edge);
                } else {
                    edge_dp[row][col] = 0;
                    row_dp[row][col] = 0;
                    col_dp[row][col] = 0;
                }
            }
        }

        return max_edge * max_edge;
    }

    int maximalSquare1D(vector<vector<char>> &matrix) {
        size_t rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        size_t cols = matrix[0].size();
        if (cols == 0) {
            return 0;
        }

        auto valid = [](char c) -> bool { return c == '1'; };

        std::vector<int> edge_dp(cols, 0);
        std::vector<int> col_dp(cols, 0);
        int max_edge = 0;
        int edge_pre = 0;

        for (size_t row = 0; row < rows; ++row) {
            int contig_row = 0;
            for (size_t col = 0; col < cols; ++col) {
                int buf = edge_dp[col];
                if (row == 0 || col == 0) {
                    edge_dp[col] = matrix[row][col] - '0';
                    col_dp[col] = matrix[row][col] - '0';
                    contig_row = matrix[row][col] - '0';
                } else {
                    if (valid(matrix[row][col])) {
                        contig_row = contig_row + 1;
                        col_dp[col] = col_dp[col] + 1;
                        edge_dp[col] =
                            std::min(std::min(col_dp[col], contig_row), edge_pre + 1);
                    } else {
                        contig_row = 0;
                        col_dp[col] = 0;
                        edge_dp[col] = 0;
                    }
                }
                edge_pre = buf;
                max_edge = std::max(max_edge, edge_dp[col]);
            }
        }
        return max_edge * max_edge;
    }

    int maximalSquare(vector<vector<char>> &matrix) { return maximalSquare1D(matrix); }
};

#endif
