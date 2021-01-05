// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*Short Explanation :
We keep track of number and its count while iterating in the original LinkedList.
If we encounter any new number, say X (i.e not matching with out stored num)
we check count of 'num', if its == 1 then we put 'num' it in the new LinkedList
we are generating. Finally, we return the new LinkedList generated.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int X, num = INT_MIN, cnt = 0;
        ListNode *Head, *temp;
        temp = Head = new ListNode();
        while (head != NULL) {
            if ((X = head->val) != num) {
                if (cnt == 1) {
                    temp->next = new ListNode(num);
                    temp = temp->next;
                }
                cnt = 1;
                num = X;
            }
            else cnt++;
            head = head->next;
        }
        if (cnt == 1)temp->next = new ListNode(num);
        return Head->next;
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
