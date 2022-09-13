#ifndef __0061_H
#define __0061_H

/***************************************************
Description:
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
***************************************************/

#include "../includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) { 
        int len = 0;
        ListNode* curPos = head;
        ListNode* tail = head;
        while(curPos != NULL) {
            curPos = curPos->next;
            len = len + 1;
            if (curPos != NULL)
                tail = curPos;
        }
        if (len == 0)
            return head;
        
        k = k % len;
        if (k == 0)
            return head;
        
        tail->next = head;
        curPos = head;
        for (int i=0; i<len-k-1; i++) {
            curPos = curPos->next;
        }
        head = curPos->next;
        curPos->next = NULL;
        return head;
    }
};

#endif