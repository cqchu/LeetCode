#ifndef __0222_H
#define __0222_H

/*****************************************************
Description:

*****************************************************/

#include "../includes.hpp"

using TreeNode = cqtree::BinaryTreeNode<int>;

class Solution {
public:
    int get_tree_height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int height = 0;
        TreeNode *cur = root;
        while (cur != nullptr) {
            cur = cur->left;
            height = height + 1;
        }
        return height;
    }

    int recurse(int total_height, int cur_depth, int cur_offset, TreeNode *cur_root) {
        int left_height = get_tree_height(cur_root->left);
        int right_height = get_tree_height(cur_root->right);

        if (left_height == 0 && right_height == 0) {
            return cur_offset * 2;
        }
        if (left_height == 1 && right_height == 0) {
            return cur_offset * 2;
        }
        if (left_height == 1 && right_height == 1) {
            return cur_offset * 2 + 1;
        }

        if (left_height > right_height) {
            return recurse(total_height, cur_depth + 1, 2 * cur_offset, cur_root->left);
        } else {
            // assert(left_height == right_height)
            return recurse(total_height, cur_depth + 1, 2 * cur_offset + 1,
                           cur_root->right);
        }
    }

    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int height = get_tree_height(root);
        int offset = recurse(height, 1, 0, root);
        return std::pow(2, height - 1) + offset;
    }
};

#endif
