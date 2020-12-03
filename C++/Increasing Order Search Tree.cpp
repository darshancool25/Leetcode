// https://leetcode.com/problems/increasing-order-search-tree/

/*Short Explanation -
Create the required tree while doing an inorder traversal
in the given BST.
*/

class Solution {
public:
    TreeNode* head, *temp;
    void inorder(TreeNode* root) {
        if (root == NULL)return;
        inorder(root->left);
        temp->right = new TreeNode(root->val);
        temp = temp->right;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        head = new TreeNode();
        temp = head;
        inorder(root);
        return head->right;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
