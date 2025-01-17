#ifndef __0019_H
#define __0019_H

/**********************************************************
Description:
Given a linked list, remove the n-th node from the end of list and return its
head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes
1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
        int len = 0, cnt = 0;
        ListNode *cur = head, *pre = head;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }

        pre = cur = head;
        while (cnt != len - n) {
            cnt++;
            pre = cur;
            cur = cur->next;
        }

        if (cur != head)
            pre->next = cur->next;
        else
            head = cur->next;
        delete cur;
        return head;
    }
};

#endif
