#ifndef __0234_H
#define __0234_H

/*****************************************************
Description:
Given the head of a singly linked list, return true if it is a
palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
*****************************************************/

#include "../includes.hpp"

using ListNode = cqlist::ListNode<int>;

class Solution {
public:
    ListNode *reverse_list(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    std::pair<ListNode *, ListNode *> split_list(ListNode *head) {
        size_t length = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            length += 1;
            cur = cur->next;
        }
        if (length == 1) {
            return {nullptr, nullptr};
        }

        size_t half = length / 2;

        ListNode *left = head, *right = nullptr;
        cur = head;
        length = 0;
        while (cur != nullptr) {
            if (length == half) {
                right = cur;
            }
            cur = cur->next;
            length += 1;
        }
        return {left, right};
    }

    bool isPalindrome(ListNode *head) {
        auto parts = split_list(head);
        ListNode *left = parts.first, *right = parts.second;
        if (left == nullptr && right == nullptr) {
            return true;
        }
        right = reverse_list(right);
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

#endif
