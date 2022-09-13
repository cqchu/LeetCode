#ifndef __0083_H
#define __0083_H

/*******************************************
Given a sorted linked list, delete all duplicates such that each element appear
only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*******************************************/

#include "../includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;

        ListNode *preNode = NULL, *curNode = head;
        while (curNode->next != NULL) {
            ListNode *nextNode = curNode->next;
            if (curNode->val == curNode->next->val) {
                if (preNode != NULL)
                    preNode->next = curNode->next;
                else
                    head = curNode->next;
                delete curNode;
            } else {
                preNode = curNode;
            }
            curNode = nextNode;
        }

        return head;
    }
};

#endif