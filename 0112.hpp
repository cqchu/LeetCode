#ifndef __0112_H
#define __0112_H

/****************************************************
Description:
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool DFS(TreeNode* root, int pathSum, int givenVal) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL) {
            if (root->val + pathSum == givenVal)
                return true;
            else
                return false;
        }
        if (DFS(root->left, pathSum + root->val, givenVal))
            return true;
        if (DFS(root->right, pathSum + root->val, givenVal))
            return true;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return DFS(root, 0, sum);
    }
};

#endif