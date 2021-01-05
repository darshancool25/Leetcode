// https://leetcode.com/problems/merge-two-sorted-lists/

/*Short Explanation :
Iterate in both lists using pointers l1, l2. Always take the smaller element
and add to our new list.
Note that this above comparison has to be done only while elements exist in both lists.
After that just empty the remaining list(s) into our new list. [As they are already sorted]
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *temp;
        temp = head = new ListNode();
        while (l1 != NULL and l2 != NULL) {
            if (l1->val < l2->val) {
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while (l1 != NULL) {
            temp->next = new ListNode(l1->val);
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            temp->next = new ListNode(l2->val);
            temp = temp->next;
            l2 = l2->next;
        }
        return head->next;
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
