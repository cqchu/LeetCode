#ifndef __0086_H
#define __0086_H

/**********************************************
Description:
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
**********************************************/

#include "includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *insertNode = NULL, *curNode = head, *preNode = NULL;
        bool fakeHead = false;
        while(curNode != NULL) {
            if (insertNode == NULL) {
                if (curNode->val >= x) {
                    if (preNode != NULL)
                        insertNode = preNode;
                    else {
                        insertNode = new ListNode(x);
                        insertNode->next = curNode;
                        head = insertNode;
                        fakeHead = true;
                    }
                }
            }
            else {
                if (curNode->val < x) {
                    preNode->next = curNode->next;
                    curNode->next = insertNode->next;
                    insertNode->next = curNode;
                    insertNode = curNode;
                    
                }
            }
            preNode = curNode;
            curNode = curNode->next;
        }
        if (fakeHead) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
            
        return head;
    }
};

#endif