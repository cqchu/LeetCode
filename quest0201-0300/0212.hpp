#ifndef __0212_H
#define __0212_H

/*****************************************************
Description:
Given an m x n board of characters and a list of strings words, return all words on the
board. Each word must be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell may not
be used more than once in a word.

Example 1:
Input: board =
[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words =
["oath","pea","eat","rain"] Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    template <typename T> using Vec2D = std::vector<std::vector<T>>;
    bool recursive(const Vec2D<char> &board, Vec2D<bool> &visited, int im, int in,
                   const std::string &word, size_t idx) {
        if (idx >= word.size()) {
            return true;
        }

        size_t m = board.size(), n = board[0].size();
        if (im < 0 || im >= m || in < 0 || in >= n) {
            return false;
        }
        if (visited[im][in] == true) {
            return false;
        }
        if (board[im][in] != word[idx]) {
            return false;
        }

        visited[im][in] = true;

        bool found = recursive(board, visited, im - 1, in, word, idx + 1) ||
                     recursive(board, visited, im + 1, in, word, idx + 1) ||
                     recursive(board, visited, im, in - 1, word, idx + 1) ||
                     recursive(board, visited, im, in + 1, word, idx + 1);
        visited[im][in] = false;
        return found;
    }

    bool find_word(const Vec2D<char> &board, const std::string &word) {
        if (word.size() == 0) {
            return true;
        }
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }

        size_t m = board.size(), n = board[0].size();
        Vec2D<bool> visited(m, std::vector<bool>(n, false));
        for (size_t im = 0; im < m; ++im) {
            for (size_t in = 0; in < n; ++in) {
                if (recursive(board, visited, im, in, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<size_t> get_feature(const std::string &word) {
        std::vector<size_t> ret(26, 0);
        for (auto ch : word) {
            ret[ch - 'a'] += 1;
        }
        return ret;
    }

    std::vector<size_t> get_feature(const Vec2D<char> &board) {
        std::vector<size_t> ret(26, 0);
        for (auto row : board) {
            for (auto ch : row) {
                ret[ch - 'a'] += 1;
            }
        }
        return ret;
    }

    bool possible(const std::vector<size_t> board_feature,
                  const std::vector<size_t> word_feature) {
        for (size_t i = 0; i < 26; ++i) {
            if (word_feature[i] > board_feature[i])
                return false;
        }
        return true;
    }

    std::string reverse(const std::string &str) {
        std::string ret(str.size(), ' ');
        for (size_t i = 0; i < str.size(); ++i) {
            ret[str.size() - 1 - i] = str[i];
        }
        return ret;
    }

    size_t score(const std::string &str) {
        size_t ret = 0;
        for (size_t i = 1; i < (str.size() / 2); ++i) {
            if (str[i] != str[i - 1]) {
                ret += 1;
            }
        }
        return ret;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        std::vector<std::string> ret;
        auto board_feature = get_feature(board);
        for (auto word : words) {
            auto word_feature = get_feature(word);
            auto reversed = reverse(word);
            if (possible(board_feature, word_feature)) {
                if (score(reversed) > score(word)) {
                    if (find_word(board, reversed)) {
                        ret.push_back(word);
                    }
                } else {
                    if (find_word(board, word)) {
                        ret.push_back(word);
                    }
                }
            }
        }
        return ret;
    }
};

#endif
