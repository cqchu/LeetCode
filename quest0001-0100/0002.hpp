#ifndef __0002_H
#define __0002_H

/****************************************************************
Description:
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order and each of their nodes
contain a single digit. Add the two numbers and return it as a linked list. You
may assume the two numbers do not contain any leading zero, except the number 0
itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*****************************************************************/

#include "../includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *start = NULL, *prevPtr = NULL, *curPtr = NULL;
        int nextAdd = 0;
        while (l1 != NULL || l2 != NULL) {
            int newValue = nextAdd;
            if (l1 != NULL) {
                newValue += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                newValue += l2->val;
                l2 = l2->next;
            }
            nextAdd = newValue / 10;
            newValue = newValue % 10;

            curPtr = new ListNode(newValue);
            if (start == NULL)
                start = prevPtr = curPtr;
            else {
                prevPtr->next = curPtr;
                prevPtr = curPtr;
            }
        }
        if (nextAdd != 0) {
            curPtr = new ListNode(nextAdd);
            prevPtr->next = curPtr;
        }
        return start;
    }
};

#endif