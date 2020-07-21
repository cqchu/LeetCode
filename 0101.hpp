#ifndef __0101_H
#define __0101_H

/****************************************************
Description:
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
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
//     void preorder(TreeNode* root, vector<int> &preSeq) {
//         if (root == NULL)
//             return;
//         preorder(root->left, preSeq);
//         preSeq.push_back(root->val);
//         preorder(root->right, preSeq);
//     }
    
//     void postorder(TreeNode* root, vector<int> &postSeq) {
//         if (root == NULL)
//             return;
//         postorder(root->right, postSeq);
//         postSeq.push_back(root->val);
//         postorder(root->left, postSeq);
//     }
    
//     bool isSymmetric(TreeNode* root) {
//         vector<int> preSeq, postSeq;
//         preorder(root, preSeq);
//         postorder(root, postSeq);
//         for (int i=0; i<preSeq.size(); i++) {
//             if (preSeq[i] != postSeq[i])
//                 return false;
//         }
//         return true;
//     }
    bool recurse(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        if ((left == NULL && right != NULL) || (left != NULL && right == NULL) || left->val != right->val)
            return false;
        return recurse(left->right, right->left) && recurse(left->left, right->right);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return recurse(root->left, root->right);
    }
};

#endif