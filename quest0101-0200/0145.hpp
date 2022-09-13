#ifndef __0145_H
#define __0145_H

/****************************************************
Description:
Given a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodeStack;
        if (root == nullptr)
            return res;
        nodeStack.push(root);
        TreeNode *pre = root;
        while (!nodeStack.empty()) {
            TreeNode *cur = nodeStack.top();            
            if (cur->right == pre || cur->left == pre || (cur->right == nullptr && cur->left == nullptr)) {
                nodeStack.pop();
                pre = cur;
                res.push_back(cur->val);
            }
            else {
                if (cur->right != nullptr)
                    nodeStack.push(cur->right);
                if (cur->left != nullptr)
                    nodeStack.push(cur->left);
            }
        }
        return res;
    }
};

#endif