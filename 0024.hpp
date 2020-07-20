#ifndef __0024_H
#define __0024_H

/**********************************************************
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
    Your algorithm should use only constant extra space.
    You may not modify the values in the list's nodes, only nodes itself may be changed.
**********************************************************/

#include "includes.hpp"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *A = NULL, *B = NULL, *C = NULL;
        ListNode *beforeHead = new ListNode(0);
        beforeHead->next = head;

        A = beforeHead;
        B = head;
        if(head != NULL)
            C = head->next;

        while(C != NULL)
        {
            B->next = C->next;
            C->next = B;
            A->next = C;

            A = B;
            B = A->next;
            if(B != NULL)
                C = B->next;
            else
                C = NULL;
        }   
        return beforeHead->next;     
    }
};

#endif
