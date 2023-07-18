#ifndef __0230_H
#define __0230_H

/*****************************************************
Description:
Given the root of a binary search tree, and an integer k, return the kth smallest value
(1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4

Follow up: If the BST is modified often (i.e., we can do insert and delete operations)
and you need to find the kth smallest frequently, how would you optimize?
*****************************************************/

#include "../includes.hpp"

using TreeNode = cqtree::BinaryTreeNode<int>;

class Solution {
public:
    void recurse(TreeNode *root, std::vector<int> &holder, int &vis_count,
                 const int k) {
        if (root == nullptr || vis_count > k) {
            return;
        }
        recurse(root->left, holder, vis_count, k);
        vis_count += 1;
        holder.push_back(root->val);
        recurse(root->right, holder, vis_count, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        std::vector<int> holder;
        holder.reserve(k);
        int vis_count = 0;
        k = k - 1;
        recurse(root, holder, vis_count, k);
        LOG_ARRAY(holder);
        return holder[k];
    }
};

#endif
