#ifndef __0103_H
#define __0103_H

/****************************************************
Description:
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        deque<TreeNode *> bfsQ;
        bfsQ.push_back(root);
        bfsQ.push_back(NULL);
        bool l2r = true;
        while (!bfsQ.empty()) {
            vector<int> curLayer;
            while(bfsQ.front() != NULL) {
                TreeNode *tmp = bfsQ.front();
                bfsQ.pop_front();
                curLayer.push_back(tmp->val);
                if (tmp->left != NULL)
                    bfsQ.push_back(tmp->left);
                if (tmp->right != NULL)
                    bfsQ.push_back(tmp->right);   
            }
            if (!curLayer.empty())
                res.push_back(curLayer);
            bfsQ.pop_front();
            if (!bfsQ.empty())
                bfsQ.push_front(NULL);
            
            curLayer.clear();
            
            while(bfsQ.back() != NULL) {
                TreeNode *tmp = bfsQ.back();
                bfsQ.pop_back();
                curLayer.push_back(tmp->val);
                if (tmp->right != NULL)
                    bfsQ.push_front(tmp->right);
                if (tmp->left != NULL)
                    bfsQ.push_front(tmp->left);   
            }
            if (!curLayer.empty())
                res.push_back(curLayer);
            bfsQ.pop_back();
            if (!bfsQ.empty())
                bfsQ.push_back(NULL);
        }
        return res;
    }
};

#endif