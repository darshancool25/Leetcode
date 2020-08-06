// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)return head;
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node *curr_next = curr->next;
                Node *x = flatten(curr->child);
                Node* end = x;

                while (end->next)end = end->next;
                end->next = curr_next;

                if (curr_next)curr_next->prev = end;

                curr->next = x;
                x->prev = curr;

                curr->child = NULL;
            }
            curr = curr->next;
        }
        return head;
    }
};
