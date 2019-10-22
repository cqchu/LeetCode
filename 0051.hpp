#ifndef __0051_H
#define __0051_H

/*************************************************
Description:
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // level: cur row, 
    void recurse(int level, vector<int>& pos, int n, vector<vector<string>>& sol) {
        if (level == n) {
            vector<string> tmp(n);
            for (int i=0; i<n; i++) {
                string s(n, '.');
                s[pos[i]] = 'Q';
                tmp[i] = s;
            }
            sol.push_back(tmp);
        }
        for (int i=0; i<n; i++) {
            // judge whether can be placed
            bool placeFlag = true;
            for (int j=0; j<level; j++) {
                if (pos[j] == i || pos[j] == i+(level-j) || pos[j] == i-(level-j)) {
                    placeFlag = false;
                    break;
                }
            }
            if (placeFlag == true) {
                pos[level] = i;
                recurse(level+1, pos, n, sol);
                pos[level] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        recurse(0, pos, n, res);
        return res;
    }
};


#endif
