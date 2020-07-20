#ifndef __0099_H
#define __0099_H

/****************************************************
Description:
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]
   1
  /
 3
  \
   2

Output: [3,1,null,null,2]
   3
  /
 1
  \
   2

Example 2:
Input: [3,1,4,null,null,2]
  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]
  2
 / \
1   4
   /
  3

Follow up:
    A solution using O(n) space is pretty straight forward.
    Could you devise a constant space solution?
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
    void inorder(TreeNode* root, vector<int> &inorderSeq, unordered_map<int, TreeNode*> &val2ptr) {
        if (root == NULL)
            return;
        inorder(root->left, inorderSeq, val2ptr);
        inorderSeq.push_back(root->val);
        val2ptr.insert({root->val, root});
        inorder(root->right, inorderSeq, val2ptr);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> inorderSeq;
        unordered_map<int, TreeNode*> val2ptr;
        inorder(root, inorderSeq, val2ptr);
        int leftVal, rightVal;
        for (int i=0; i<inorderSeq.size(); i++) {
            if (inorderSeq[i] > inorderSeq[i+1]) {
                leftVal = inorderSeq[i];
                break;
            }
        }
        for (int i=inorderSeq.size()-1; i>=0; i--) {
            if (inorderSeq[i] < inorderSeq[i-1]) {
                rightVal = inorderSeq[i];
                break;
            }
        }
        
        swap(val2ptr[leftVal]->val, val2ptr[rightVal]->val);
    }
};

#endif