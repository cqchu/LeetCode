#ifndef __0113_H
#define __0113_H

/****************************************************
Description:
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void DFS(TreeNode* root, int pathSum, int givenVal, vector<int> &visitStack, vector<vector<int>> &res) {
        if (root == NULL)
            return;
        visitStack.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val + pathSum == givenVal) 
                res.push_back(visitStack);
        }
        DFS(root->left, pathSum + root->val, givenVal, visitStack, res);
        DFS(root->right, pathSum + root->val, givenVal, visitStack, res);
        visitStack.pop_back();
        return;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> visitStack;
        vector<vector<int>> res;
        DFS(root, 0, sum, visitStack, res);
        return res;
    }
};

#endif