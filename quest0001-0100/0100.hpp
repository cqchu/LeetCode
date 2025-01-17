#ifndef __0100_H
#define __0100_H

/****************************************************
Description:
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and
the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
Output: true

Example 2:
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]
Output: false

Example 3:
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
Output: false
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
    bool checkTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL) || (p->val != q->val))
            return false;
        return checkTree(p->left, q->left) & checkTree(p->right, q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) { return checkTree(p, q); }
};

#endif