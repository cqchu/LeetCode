#ifndef __0025_H
#define __0025_H

/**********************************************************
Description:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.
**********************************************************/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reverseK(ListNode *head, ListNode *tail, int k)
    {
        if(head == NULL || tail == NULL || head == tail)
            return;

        ListNode *pre = head , *cur = head->next, *tmpNext = NULL;
        for(int i=1; i<k; i++)
        {
            tmpNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmpNext;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *beforeHead = new ListNode(0);
        beforeHead->next = head;

        ListNode *before=beforeHead, *after=NULL, *tmpHead=NULL, *tmpTail=NULL;
        while(true) 
        {
            if(tmpTail != NULL)
                before = tmpTail;
            tmpHead = tmpTail = before->next;
            for(int i=0; i<k-1 && tmpTail!=NULL; i++)
                tmpTail = tmpTail->next;
            
            if(tmpTail == NULL)
                break;
            after = tmpTail->next;
            reverseK(tmpHead, tmpTail, k);
            ListNode *tmp = tmpHead;
            tmpHead = tmpTail;
            tmpTail = tmp; 

            before->next = tmpHead;
            tmpTail->next = after;
        }
        return beforeHead->next;
    }
};

#endif

