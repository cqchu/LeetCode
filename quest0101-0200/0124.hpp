#ifndef __0124_H
#define __0124_H

/****************************************************
Description:
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting
node to any node in the tree along the parent-child connections. The path must
contain at least one node and does not need to go through the root.

Example 1:
Input: [1,2,3]
       1
      / \
     2   3
Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
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
    long maxSubTree(TreeNode *root, long &curMax) {
        if (root == NULL)
            return -INT_MAX;
        long leftMax = maxSubTree(root->left, curMax);
        long rightMax = maxSubTree(root->right, curMax);
        long tmpMax = max(static_cast<long>(root->val), max(leftMax, rightMax));
        tmpMax = max(tmpMax, max(leftMax + root->val, rightMax + root->val));
        tmpMax = max(tmpMax, root->val + leftMax + rightMax);

        curMax = max(curMax, tmpMax);
        return max(static_cast<long>(root->val),
                   max(root->val + leftMax, root->val + rightMax));
    }
    int maxPathSum(TreeNode *root) {
        long maxPath = -INT_MAX;
        maxSubTree(root, maxPath);
        return static_cast<int>(maxPath);
    }
};

#endif
