#ifndef __0104_H
#define __0104_H

/****************************************************
Description:
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
****************************************************/

#include "../includes.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void DFS(TreeNode *root, int curDepth, int &globalMax) {
        if (root == NULL) {
            globalMax = globalMax < curDepth ? curDepth : globalMax;
            return;
        }
        DFS(root->left, curDepth + 1, globalMax);
        DFS(root->right, curDepth + 1, globalMax);
    }
    int maxDepth(TreeNode *root) {
        int globalMax = 0;
        DFS(root, 0, globalMax);
        return globalMax;
    }
};

#endif