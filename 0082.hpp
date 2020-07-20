#ifndef __0082_H
#define __0082_H

/******************************************************
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
******************************************************/

#include "includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        
        ListNode *lastDicNode=NULL, *curNode=head;
        bool duplicateFlag = false;
        while(curNode->next != NULL) {
            ListNode *nextNode = curNode->next;
            if (curNode->val == curNode->next->val) {
                if (lastDicNode != NULL)
                    lastDicNode->next = curNode->next;
                else 
                    head = curNode->next;
                delete curNode;
                duplicateFlag = true;
            }
            else {
                if (duplicateFlag == true) {
                    if (lastDicNode != NULL)
                        lastDicNode->next = curNode->next;
                    else 
                        head = curNode->next;
                    delete curNode;
                    duplicateFlag = false;
                }
                else {
                    lastDicNode = curNode;
                }
                
            }
            curNode = nextNode;
        }
        if (duplicateFlag == true) {
            if (lastDicNode != NULL) 
                lastDicNode->next = NULL;
            else 
                head = NULL;
            delete curNode;
        }
        return head;
    }
};

#endif