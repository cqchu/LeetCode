#ifndef __0102_H
#define __0102_H

/****************************************************
Description:
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> bfsQ;
        bfsQ.push(root);
        bfsQ.push(NULL);
        while (!bfsQ.empty()) {
            vector<int> curLayer;
            while(bfsQ.front() != NULL) {
                TreeNode *tmp = bfsQ.front();
                bfsQ.pop();
                curLayer.push_back(tmp->val);
                if (tmp->left != NULL)
                    bfsQ.push(tmp->left);
                if (tmp->right != NULL)
                    bfsQ.push(tmp->right);   
            }
            res.push_back(curLayer);
            bfsQ.pop();
            if (!bfsQ.empty())
                bfsQ.push(NULL);
        }
        return res;
    }
};

#endif