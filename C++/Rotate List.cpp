// https://leetcode.com/problems/rotate-list/

/*Short Explanation :
Trivial Cases : if head==NULL OR (k % len==0) return head;
else remove the last k elements from the list, and append
them to the beginning of the list.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)return NULL;
        int len = 1, curr = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            len++;
            temp = temp->next;
        }
        k %= len;
        if (k == 0)return head;
        temp = head;
        while (curr < len - k) {
            temp = temp->next;
            curr++;
        }
        ListNode* newhead = temp->next;
        temp->next = NULL;
        temp = newhead;
        while (temp->next != NULL)temp = temp->next;
        temp->next = head;
        return newhead;
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
