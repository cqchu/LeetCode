#ifndef __0174_H
#define __0174_H

/*****************************************************
Description:
The demons had captured the princess and imprisoned her in the bottom-right
corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid.
Our valiant knight was initially positioned in the top-left room and must fight
his way through dungeon to rescue the princess.

The knight has an initial max_reserve point represented by a positive integer.
If at any point his max_reserve point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so
the knight loses max_reserve upon entering these rooms; other rooms are either
empty (represented as 0) or contain magic orbs that increase the knight's
max_reserve (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only
rightward or downward in each step.

Return the knight's minimum initial max_reserve so that he can rescue the
princess.

Note that any room can contain threats or power-ups, even the first room the
knight enters and the bottom-right room where the princess is imprisoned.

Example 1:
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial max_reserve of the knight must be at least 7 if he
follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN. Example 2:

Input: dungeon = [[0]]
Output: 1

Constraints:
m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000
*****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int cal_consume(int update, int cur_consume) {
        if (update < 0 && cur_consume <= 0)
            return -update;
        else
            return cur_consume - update;
    }

    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (dungeon[m - 1][n - 1] >= 0)
            dp[m - 1][n - 1] = 0;
        else
            dp[m - 1][n - 1] = -dungeon[m - 1][n - 1];

        // LOG_ARRAY2D(dp);

        for (int i = m - 2; i >= 0; --i)
            dp[i][n - 1] = cal_consume(dungeon[i][n - 1], dp[i + 1][n - 1]);

        for (int i = n - 2; i >= 0; --i)
            dp[m - 1][i] = cal_consume(dungeon[m - 1][i], dp[m - 1][i + 1]);

        // LOG_ARRAY2D(dp);

        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                dp[i][j] = min(cal_consume(dungeon[i][j], dp[i + 1][j]),
                               cal_consume(dungeon[i][j], dp[i][j + 1]));
        // LOG_ARRAY2D(dp);
        return dp[0][0] > 0 ? dp[0][0] + 1 : 1;
    }
};

#endif
