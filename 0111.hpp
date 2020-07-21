#ifndef __0111_H
#define __0111_H

/****************************************************
Description:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
****************************************************/

#include "includes.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void DFS(TreeNode* root, int curDepth, int &minDepth) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            minDepth = curDepth > minDepth ? minDepth : curDepth;
            return;
        }
        DFS(root->left, curDepth+1, minDepth);
        DFS(root->right, curDepth+1, minDepth);
    }
    
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int minDepth = INT_MAX;
        DFS(root, 1, minDepth);
        return minDepth;
    }
};

#endif