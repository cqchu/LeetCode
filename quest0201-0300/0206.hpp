#ifndef __0206_H
#define __0206_H

/*****************************************************
Description:
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you
implement both?
*****************************************************/

#include "../includes.hpp"

using ListNode = ::list::ListNode<int>;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::stack<ListNode *> s;
        while (head != nullptr) {
            s.push(head);
            head = head->next;
        }
        auto pre = head = s.top();
        s.pop();
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            pre->next = cur;
            pre = cur;
        }
        pre->next = nullptr;
        return head;
    }
};

#endif
