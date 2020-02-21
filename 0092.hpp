#ifndef __0092_H
#define __0092_H

/****************************************************
Description:
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
****************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *subTail = NULL, *frontEnd = NULL, *cur = head, *pre = NULL, *next = NULL;
        int cnt = 1;
        for (; cnt<m; cnt++) {
            frontEnd = cur;
            cur = cur->next;
        }
        subTail = cur;
        pre = cur;
        cur = cur->next;
        
        // cout << cnt << " " << frontEnd->val << " " << cur->val << endl;
        for (; cnt < n; cnt ++) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        subTail->next = cur;
        if (frontEnd != NULL)
            frontEnd->next = pre;
        else
            head = pre;
        return head;
    }
};

#endif