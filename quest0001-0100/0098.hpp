#ifndef __0098_H
#define __0098_H

/****************************************************
Description:
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the
node's key. The right subtree of a node contains only nodes with keys greater
than the node's key. Both the left and right subtrees must also be binary
search trees.

Example 1:
    2
   / \
  1   3
Input: [2,1,3]
Output: true

Example 2:
    5
   / \
  1   4
     / \
    3   6
Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
    bool cheakSubTree(TreeNode *root, long min, long max) {
        if (root == NULL)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return cheakSubTree(root->left, min, root->val) &
               cheakSubTree(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root) { return cheakSubTree(root, -LONG_MAX, LONG_MAX); }
};

#endif