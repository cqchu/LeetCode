#ifndef __0108_H
#define __0108_H

/****************************************************
Description:
Given an array where elements are sorted in ascending order, convert it to a
height balanced BST. For this problem, a height-balanced binary tree is defined
as a binary tree in which the depth of the two subtrees of every node never
differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode *createSubTree(vector<int> &nums, int left, int right) {
        if (left >= right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = createSubTree(nums, left, mid);
        root->right = createSubTree(nums, mid + 1, right);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return createSubTree(nums, 0, nums.size());
    }
};

#endif