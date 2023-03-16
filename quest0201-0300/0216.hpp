#ifndef __0216_H
#define __0216_H

/*****************************************************
Description:
Find all valid combinations of k numbers that sum up to n such that the following
conditions are true:
* Only numbers 1 through 9 are used.
* Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same
combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 =
10 and since 10 > 1, there are no valid combination.

Constraints:
2 <= k <= 9
1 <= n <= 60
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    void dfs(std::vector<std::vector<int>> &res, std::vector<int> &vis, int depth,
             int curval, int presum, int target_val, int target_depth) {
        presum = presum + curval;
        depth = depth + 1;
        if (presum > target_val || depth > target_depth) {
            return;
        }
        vis.push_back(curval);
        if (presum == target_val && depth == target_depth) {
            res.push_back(vis);
            vis.pop_back();
            return;
        }
        for (int i = curval - 1; i > 0; --i) {
            dfs(res, vis, depth, i, presum, target_val, target_depth);
        }
        vis.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> vis;
        for (int i = 9; i > 0; --i)
            dfs(res, vis, 0, i, 0, n, k);
        return res;
    }
};

#endif
