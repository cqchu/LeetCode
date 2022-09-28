#ifndef __0106_H
#define __0106_H

/****************************************************
Description:
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode *buildSubTree(vector<int> &postorder, vector<int> &inorder, int postStart,
                           int inStart, int len) {
        if (len == 0)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postStart + len - 1]);
        int leftLen = 0;
        for (leftLen = 0; leftLen < len; leftLen++) {
            if (inorder[leftLen + inStart] == postorder[postStart + len - 1])
                break;
        }
        root->left = buildSubTree(postorder, inorder, postStart, inStart, leftLen);
        root->right = buildSubTree(postorder, inorder, postStart + leftLen,
                                   inStart + leftLen + 1, len - leftLen - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildSubTree(postorder, inorder, 0, 0, postorder.size());
    }
};

#endif