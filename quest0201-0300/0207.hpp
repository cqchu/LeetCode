#ifndef __0207_H
#define __0207_H

/*****************************************************
Description:
here are a total of numCourses courses you have to take, labeled from 0 to numCourses
- 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates
that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take
course 1. Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also
have finished course 1. So it is impossible.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= a i, bi < numCourses
All the pairs prerequisites[i] are unique
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> indegree;

        for (int i = 0; i < numCourses; ++i) {
            indegree[i] = {};
        }

        for (auto &&prerequisit : prerequisites) {
            indegree[prerequisit[0]].emplace(prerequisit[1]);
        }

        while (!indegree.empty()) {
            auto iter = indegree.begin();
            for (; iter != indegree.end(); ++iter) {
                if (iter->second.size() == 0) {
                    break;
                }
            }
            if (iter == indegree.end()) {
                return false;
            } else {
                int learned = iter->first;
                indegree.erase(iter);
                for (iter = indegree.begin(); iter != indegree.end(); ++iter) {
                    if (iter->second.find(learned) != iter->second.end()) {
                        iter->second.erase(learned);
                    }
                }
            }
        }
        return true;
    }
};

#endif
