#ifndef __0144_H
#define __0144_H

/****************************************************
Description:
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
****************************************************/

#include "../includes.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodeStack;
        if (root == nullptr)
            return res;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode *cur = nodeStack.top();
            nodeStack.pop();
            res.push_back(cur->val);
            
            if (cur->right != nullptr)
                nodeStack.push(cur->right);
            if (cur->left != nullptr)
                nodeStack.push(cur->left);
        }
        return res;
        
    }
};

#endif