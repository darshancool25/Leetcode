// https://leetcode.com/problems/merge-k-sorted-lists/

/*Approach 1 : Easy to implement
Traverse thru all linked lists and store the elements in a vector.
Sort the vector and convert it back into a linked list.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vect;
        for (auto head : lists) {
            ListNode* temp = head;
            while (temp != NULL) {
                vect.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(vect.begin() , vect.end());
        ListNode* head, *temp;
        temp = head = new ListNode(0);
        for (auto x : vect) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        return head->next;
    }
};

/*Approach 2 : Using Min Heap
Insert first element of all lists in a min heap.
While(min heap is not empty) :
    1. put minimum element of heap in new LinkedList
    2. pop the element from heap
    3. push the next element of popped node in the heap

return the new Linked List
*/

class Solution {
public:
    struct compare {
    public:
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head, *temp;
        temp = head = new ListNode(0);
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto first : lists) {
            if (first != NULL)pq.push(first);
        }
        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
            if (temp->next != NULL)pq.push(temp->next);
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
