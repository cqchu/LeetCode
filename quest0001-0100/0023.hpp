#ifndef __0023_H
#define __0023_H

/**********************************************************
Merge k sorted linked lists and return it as one sorted list. Analyze and
describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
**********************************************************/

#include "../includes.hpp"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        ListNode *minPtr = NULL;

        do {
            minPtr = NULL;
            int idx = -1;
            for (int i = 0; i < lists.size(); i++) // get min
            {
                if (lists[i] != NULL) {
                    if (minPtr == NULL) {
                        minPtr = lists[i];
                        idx = i;
                    } else {
                        if (minPtr->val > lists[i]->val) {
                            minPtr = lists[i];
                            idx = i;
                        }
                    }
                }
            }

            if (minPtr != NULL) {
                if (head == NULL)
                    head = cur = minPtr;
                else {
                    cur->next = minPtr;
                    cur = cur->next;
                }

                lists[idx] = lists[idx]->next;
            }
        } while (minPtr != NULL);

        return head;
    }
};

#endif
