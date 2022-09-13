#ifndef __0117_H
#define __0117_H

/****************************************************
Description:
Given a binary tree
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL. Initially, all next pointers
are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count
as extra space for this problem.

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should
populate each next pointer to point to its next right node, just like in Figure
B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.

Constraints:
The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
****************************************************/

#include "../includes.hpp"

// Definition for a Node.
class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node *connect(Node *root) {
        if (root == NULL)
            return root;

        Node *levelStart = root;

        // for each level
        while (levelStart != NULL) {
            Node *prePtr = NULL, *curPtr = levelStart;
            levelStart = NULL;
            // connect this level
            while (curPtr != NULL) {
                if (curPtr->left == NULL && curPtr->right == NULL) {
                    curPtr = curPtr->next;
                    continue;
                }
                if (prePtr == NULL)
                    levelStart =
                        curPtr->left != NULL ? curPtr->left : curPtr->right;

                if (prePtr != NULL) {
                    Node *preConnectSub =
                        prePtr->right != NULL ? prePtr->right : prePtr->left;
                    Node *curConnectSub =
                        curPtr->left != NULL ? curPtr->left : curPtr->right;
                    preConnectSub->next = curConnectSub;
                }
                if (curPtr->left != NULL && curPtr->right != NULL)
                    curPtr->left->next = curPtr->right;

                prePtr = curPtr;
                curPtr = curPtr->next;
            }
        }
        return root;
    }
};

#endif
