#ifndef __0110_H
#define __0110_H

/****************************************************
Description:
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in
height by no more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:
    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
    bool getDepth(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = -1;
            return true;
        }

        int leftDepth, rightDepth;
        if (!getDepth(root->left, leftDepth))
            return false;
        if (!getDepth(root->right, rightDepth))
            return false;
        if (abs(leftDepth - rightDepth) > 1)
            return false;
        depth = max(leftDepth, rightDepth) + 1;
        return true;
    }

    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return getDepth(root, depth);
    }
};

#endif