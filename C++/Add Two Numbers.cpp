// https://leetcode.com/problems/add-two-numbers/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode* node = new ListNode(), *head;
        head = node;
        while (true) {
            sum = 0;
            if (l1 != NULL) sum += l1->val;
            if (l2 != NULL) sum += l2->val;
            sum += carry;
            node->val = sum % 10;
            carry = sum / 10;
            if (l1 != NULL)l1 = l1->next;
            if (l2 != NULL)l2 = l2->next;
            if (l1 != NULL or l2 != NULL or carry) {
                node->next = new ListNode();
                node = node->next;
            }
            else break;
        }
        return head;
    }
};

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
