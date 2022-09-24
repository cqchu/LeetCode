#ifndef __0094_H
#define __0094_H

/****************************************************
Description:
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void recurse(TreeNode *root, vector<int> &res) {
        if (root == NULL)
            return;
        recurse(root->left, res);
        res.push_back(root->val);
        recurse(root->right, res);
    }

    void iterative(TreeNode *root, vector<int> &res) {
        if (root == NULL)
            return;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *cur = root->left;
        while (!st.empty() || cur != NULL) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *mid = st.top();
            st.pop();
            res.push_back(mid->val);
            cur = mid->right;
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        // recurse(root, res);
        iterative(root, res);
        return res;
    }
};

#endif