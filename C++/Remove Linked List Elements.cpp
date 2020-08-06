// https://leetcode.com/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)return head;
        ListNode* ans = head;
        while (ans != NULL and ans->val == val)ans = ans->next;
        ListNode* curr = ans;
        while (curr != NULL) {
            if (curr->next != NULL and (curr->next)->val == val) {
                curr->next = (curr->next)->next;
                continue;
            }
            curr = curr->next;
        }
        return ans;
    }
};
