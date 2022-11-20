#ifndef __0210_H
#define __0210_H

/*****************************************************
Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses
- 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates
that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take
course 1. Return the ordering of courses you should take to finish all courses. If there
are many valid answers, return any of them. If it is impossible to finish all courses,
return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have
finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have
finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished
course 0. So one correct course order is [0,1,2,3]. Another correct ordering is
[0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*****************************************************/

#include "../includes.hpp"

struct Node {
    int val;
    std::unordered_set<Node *> from;
    std::unordered_set<Node *> to;
    Node(int v) : val(v) {}
};

struct Graph {
    std::unordered_map<int, Node *> gnodes;
    std::unordered_set<Node *> zero_degrees;

    Node *make_node(int val) {
        Node *node = new Node(val);
        gnodes[val] = node;
        zero_degrees.emplace(node);
        return node;
    }
    void make_edge(int from, int to) {
        gnodes[from]->to.insert(gnodes[to]);
        gnodes[to]->from.insert(gnodes[from]);
        zero_degrees.erase(gnodes[to]);
    }
    int pop() {
        if (zero_degrees.size() == 0) {
            return -1;
        }
        auto iter = zero_degrees.begin();
        Node *node = *iter;
        zero_degrees.erase(node);
        for (auto &&t : node->to) {
            t->from.erase(node);
            if (t->from.size() == 0) {
                zero_degrees.emplace(t);
            }
        }
        return node->val;
    }
    Graph(int node_cnt) {
        gnodes.reserve(node_cnt);
        zero_degrees.reserve(node_cnt);

        for (int nid = 0; nid < node_cnt; ++nid) {
            make_node(nid);
        }
    }
    ~Graph() {
        for (auto &&kv : gnodes) {
            delete kv.second;
        }
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        Graph g(numCourses);

        for (auto &&prerequisity : prerequisites) {
            g.make_edge(prerequisity[1], prerequisity[0]);
        }

        std::vector<int> ret(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            auto next = g.pop();
            if (next == -1) {
                return {};
            }
            ret[i] = next;
        }
        return ret;
    }
};

#endif
