#ifndef __0021_H
#define __0021_H

/**********************************************************
Description:
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
**********************************************************/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *cur = NULL;
        while(l1!=NULL || l2!=NULL)
        {
            ListNode *tmp; 
            if(l1 == NULL)
                tmp = l2;
            else if(l2 == NULL)
                tmp = l1;
            else
                tmp = (l1->val > l2->val) ? l2 : l1;
            if(head == NULL)
                head = cur = tmp;
            else
            {
                cur->next = tmp;
                cur = cur->next;
            }

            if(tmp == l1)
                l1 = l1->next;
            else
                l2 = l2->next; 
        }
        return head;
    }
};

#endif

