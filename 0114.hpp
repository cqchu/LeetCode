#ifndef __0114_H
#define __0114_H

/****************************************************
Description:
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:
    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        stack<TreeNode *> helper;
        helper.push(root);
        TreeNode *pre = NULL, *cur = NULL;
        while(!helper.empty()) {
            cur = helper.top();
            helper.pop();
            if (cur->right != NULL)
                helper.push(cur->right);
            if (cur->left != NULL)
                helper.push(cur->left);
            cur->left = NULL;
            cur->right = NULL;
            
            if (pre != NULL)
                pre->right = cur;
            pre = cur;
        }
    }
};

#endif
