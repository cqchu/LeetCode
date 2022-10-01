#ifndef __0203_H
#define __0203_H

/*****************************************************
Description:
Given the head of a linked list and an integer val, remove all the nodes of the linked
list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []

Constraints:
The number of nodes in the list is in the range [0, 10^4].
1 <= Node.val <= 50
0 <= val <= 50
*****************************************************/

#include "../includes.hpp"

using ListNode = list::ListNode<int>;

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            if (cur->val == val) {
                if (pre != nullptr) {
                    pre->next = cur->next;
                } else {
                    head = cur->next;
                }
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

#endif
