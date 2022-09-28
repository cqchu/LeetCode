#ifndef __0105_H
#define __0105_H

/****************************************************
Description:
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int preStart,
                           int inStart, int len) {
        if (len == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int leftLen = 0;
        for (leftLen = 0; leftLen < len; leftLen++) {
            if (inorder[leftLen + inStart] == preorder[preStart])
                break;
        }
        root->left = buildSubTree(preorder, inorder, preStart + 1, inStart, leftLen);

        root->right = buildSubTree(preorder, inorder, preStart + leftLen + 1,
                                   inStart + leftLen + 1, len - leftLen - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildSubTree(preorder, inorder, 0, 0, preorder.size());
    }
};

#endif