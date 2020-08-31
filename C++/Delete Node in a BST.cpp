// https://leetcode.com/problems/delete-node-in-a-bst/

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
class Solution {
public:

    TreeNode* modify(TreeNode* left, TreeNode* right) {
        if (left == NULL)return right;
        left->right = modify(left->right, right);
        return left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)return NULL;
        if (root->val == key)return modify(root->left , root->right);
        if (root->val > key)root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};
