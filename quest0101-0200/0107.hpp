#ifndef __0107_H
#define __0107_H

/****************************************************
Description:
Given a binary tree, return the bottom-up level order traversal of its nodes'
values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    TreeNode *buildSubTree(vector<int> &postorder, vector<int> &inorder,
                           int postStart, int inStart, int len) {
        if (len == 0)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postStart + len - 1]);
        int leftLen = 0;
        for (leftLen = 0; leftLen < len; leftLen++) {
            if (inorder[leftLen + inStart] == postorder[postStart + len - 1])
                break;
        }
        root->left =
            buildSubTree(postorder, inorder, postStart, inStart, leftLen);
        root->right = buildSubTree(postorder, inorder, postStart + leftLen,
                                   inStart + leftLen + 1, len - leftLen - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildSubTree(postorder, inorder, 0, 0, postorder.size());
    }
};

#endif