#ifndef __0148_H
#define __0148_H

/****************************************************
Description:
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
****************************************************/

#include "includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void print(ListNode *head) {
        while(head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode *merge(ListNode *lhs, ListNode *rhs) {
        if (lhs == nullptr) return rhs;
        if (rhs == nullptr) return lhs;
        ListNode *head = lhs->val < rhs->val ? lhs : rhs;
        ListNode *lhsPtr = lhs == head ? lhs->next : lhs;
        ListNode *rhsPtr = rhs == head ? rhs->next : rhs;
        ListNode *cur = head;
        head->next = nullptr;
        while (lhsPtr != nullptr || rhsPtr != nullptr) {
            if (lhsPtr == nullptr) {
                cur->next = rhsPtr;
                break;
            }
            else if (rhsPtr == nullptr) {
                cur->next = lhsPtr;
                break;
            }
            else if (lhsPtr->val < rhsPtr->val) {
                cur->next = lhsPtr;
                lhsPtr = lhsPtr->next;
                cur = cur->next;
                cur->next = nullptr;
            }
            else {
                cur->next = rhsPtr;
                rhsPtr = rhsPtr->next;
                cur = cur->next;
                cur->next = nullptr;
            }
        }
        return head;
    }
    
    pair<ListNode*, ListNode*> divide(ListNode *head) {
        ListNode *lhs, *rhs;
        if (head == nullptr || head->next == nullptr) {
            lhs = head;
            rhs = nullptr;
            return make_pair(lhs, rhs);
        }
        ListNode *fast=head, *slow=head, *slowPre=nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slowPre = slow;
            slow = slow->next;
            
        }
        slowPre->next = nullptr;
        lhs = head;
        rhs = slow;
        return make_pair(lhs, rhs);
    }
    
    ListNode* divideAndConquer(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *lhs, *rhs;
        // print(head);
        auto divideRes = divide(head);
        divideRes.first = divideAndConquer(divideRes.first);
        divideRes.second = divideAndConquer(divideRes.second);        
        head = merge(divideRes.first, divideRes.second);
        // cout << "---------" << endl;
        // print(divideRes.first);
        // print(divideRes.second);
        // print(head);
        // cout << "---------" << endl;
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        return divideAndConquer(head);
    }
};

#endif