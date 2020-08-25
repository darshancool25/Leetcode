// https://leetcode.com/problems/sum-of-left-leaves/

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
    bool isLeaf(TreeNode* node) {
        return (node->left == NULL and node->right == NULL);
    }
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (root == NULL)return 0;
        int cnt = 0;
        if (isLeaf(root) and isLeft)cnt += root->val;
        return cnt + sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
