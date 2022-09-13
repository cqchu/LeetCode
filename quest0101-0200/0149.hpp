#ifndef __0149_H
#define __0149_H

/****************************************************
Description:
Given n points on a 2D plane, find the maximum number of points that lie on the
same straight line.

Example 1:
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4

Example 2:
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.size() == 0 || points.size() == 1)
            return points.size();
        sort(points.begin(), points.end(),
             [](const auto &lhs, const auto &rhs) {
                 return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
             });
        vector<map<double, int>> dp;
        map<double, int> m;
        for (int i = 0; i < points.size(); i++)
            dp.push_back(m);
        int ans = 0;

        int n = points.size();
        map<int, int> dup;
        for (int i = 0; i < n; i++)
            dup[i] = 1;
        for (int i = 1; i < n; i++) {
            vector<int> &p1 = points[i];
            vector<int> &p2 = points[i - 1];
            if (p1[0] == p2[0] && p1[1] == p2[1])
                dup[i] = dup[i - 1] + 1;
        }
        for (int i = 0; i < points.size(); i++) {
            map<double, int> &m1 = dp[i];
            double x1 = points[i][0];
            double y1 = points[i][1];
            for (int j = 0; j < i; j++) {
                double x0 = points[j][0];
                double y0 = points[j][1];
                map<double, int> &m0 = dp[j];
                if (x1 == x0 && y1 == y0)
                    continue;

                double slope = (y1 - y0) / (x1 - x0);
                if (m0.find(slope) == m0.end())
                    m1[slope] = dup[i] + dup[j];
                else
                    m1[slope] = m0[slope] + dup[i];
                ans = max(m1[slope], ans);
            }
        }

        for (int i = 0; i < n; i++)
            ans = max(ans, dup[i]);

        return ans;
    }
};

#endif