#ifndef __0095_H
#define __0095_H

/****************************************************
Description:
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

****************************************************/

#include "includes.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * for BST(Binary Search Tree) with N node, it can be composed as below:
 * case 1:               case 2:              case 3:
 *            N             Tree [1, N)           Tree [1, j)
 *           /                    \                   \ 
 *          /                      \                   \
 *    Tree [1, N)                   N                   N
 *                                                     /
 *                                                    /
 *                                             Tree [j, N)
 * case 1 can be seen as the special case with j=1
 * case 2 can be seen as the special case with j=N
 */

class Solution {
public:
    TreeNode *copyTree(TreeNode *root) {
        if (root == NULL)
            return NULL;
        
        TreeNode *copyRoot = new TreeNode(root->val);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }
    
    // base used for converting a tree [1, n] to a tree [base+1, base+n] 
    vector<TreeNode*> recurse(int n, int base) {
        vector<TreeNode*> res;
        if (n == 0)
            return res;
        if (n == 1) {
            res.push_back(new TreeNode(1+base));
            return res;
        }
        for (int j=0; j<n; j++) {
         
            vector<TreeNode*> topRes = recurse(j, base);
            vector<TreeNode*> bottomRes = recurse(n-j-1, j+base);
            
            if (topRes.empty())
                topRes.push_back(NULL);
            if (bottomRes.empty())
                bottomRes.push_back(NULL);
                        
            for (auto top: topRes) {
                for (auto bottom: bottomRes) {
                    TreeNode* curNode = new TreeNode(n+base);
                    curNode->left = bottom;
                    if (top != NULL) {
                        TreeNode *tmpTop = copyTree(top); 
                        res.push_back(tmpTop);
                        while (tmpTop->right != NULL)
                            tmpTop = tmpTop->right;
                        tmpTop->right = curNode;
                    }
                    else {
                        res.push_back(curNode);
                    }
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return recurse(n,0);
    }
};

#endif