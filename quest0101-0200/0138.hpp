#ifndef __0138_H
#define __0138_H

/****************************************************
Description:
A linked list is given such that each node contains an additional random
pointer which could point to any node in the list or null. Return a deep copy
of the list. The Linked List is represented in the input/output as a list of n
nodes. Each node is represented as a pair of [val, random_index] where: val: an
integer representing Node.val random_index: the index of the node (range from 0
to n-1) where random pointer points to, or null if it does not point to any
node.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Example 4:
Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.

Constraints:
-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.
****************************************************/

#include "../includes.hpp"

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node *, Node *> src2dst;
        Node *cur = head;
        while (cur != nullptr) {
            Node *newNode = new Node(cur->val);
            src2dst[cur] = newNode;
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr) {
            if (cur->next != nullptr) {
                src2dst[cur]->next = src2dst[cur->next];
            }
            if (cur->random != nullptr) {
                src2dst[cur]->random = src2dst[cur->random];
            }
            cur = cur->next;
        }
        return src2dst[head];
    }
};

#endif