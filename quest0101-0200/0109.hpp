#ifndef __0109_H
#define __0109_H

/****************************************************
Description:
Given a singly linked list where elements are sorted in ascending order, convert
it to a height balanced BST. For this problem, a height-balanced binary tree is
defined as a binary tree in which the depth of the two subtrees of every node
never differ by more than 1.

Example:
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
****************************************************/

#include "../includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        return createSubTree(nums, 0, nums.size());
    }
};

#endif