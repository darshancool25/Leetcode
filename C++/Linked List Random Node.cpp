// https://leetcode.com/problems/linked-list-random-node/

/*Short Explanation -
Store the linkedlist nodes in a vector. return a
random element from the vector !
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> vect;
    int curr = 0, sz;
    Solution(ListNode* head) {
        while (head != NULL) {
            vect.push_back(head->val);
            head = head->next;
        }
        sz = vect.size();
    }
    /** Returns a random node's value. */
    int getRandom() {
        return vect[rand() % sz];
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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
