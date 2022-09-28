#ifndef __0199_H
#define __0199_H

/*****************************************************
Description:
Given the root of a binary tree, imagine yourself standing on the right side of
it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*****************************************************/

#include "../includes.hpp"

using TreeNode = tree::BinaryTreeNode<int>;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        std::vector<int> ret;

        std::queue<TreeNode *> helper;
        helper.push(root);
        helper.push(nullptr);

        int preval = root->val;
        while (!helper.empty()) {
            auto cur = helper.front();
            helper.pop();
            if (cur == nullptr) {
                ret.push_back(preval);
                if (!helper.empty()) {
                    helper.push(nullptr);
                }
                continue;
            } else {
                if (cur->left) {
                    helper.push(cur->left);
                }
                if (cur->right) {
                    helper.push(cur->right);
                }
            }
            preval = cur->val;
        }
        return ret;
    }
};

#endif
