#ifndef __0147_H
#define __0147_H

/****************************************************
Description:
Sort a linked list using insertion sort.

A graphical example of insertion sort. The partial sorted list (black) initially
contains only the first element in the list. With each iteration one element
(red) is removed from the input data and inserted in-place into the sorted list

Algorithm of Insertion Sort:
Insertion sort iterates, consuming one input element each repetition, and
growing a sorted output list. At each iteration, insertion sort removes one
element from the input data, finds the location it belongs within the sorted
list, and inserts it there. It repeats until no input elements remain.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
****************************************************/

#include "../includes.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        ListNode *dstHead = head;
        ListNode *srcCur = head->next;
        dstHead->next = nullptr;
        while (srcCur != nullptr) {
            ListNode *dstCur = dstHead, *dstPre = nullptr;
            while (dstCur != nullptr && dstCur->val < srcCur->val) {
                dstPre = dstCur;
                dstCur = dstCur->next;
            }
            if (dstPre == nullptr) {
                dstHead = srcCur;
                srcCur = srcCur->next;
                dstHead->next = dstCur;
            }
            // else if (dstCur == nullptr) {
            //     dstPre->next = srcCur;
            //     srcCur = srcCur->next;
            //     dstPre->next->next = dstCur;
            // }
            else {
                dstPre->next = srcCur;
                srcCur = srcCur->next;
                dstPre->next->next = dstCur;
            }
        }
        return dstHead;
    }
};

#endif