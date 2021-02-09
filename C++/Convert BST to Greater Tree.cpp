// https://leetcode.com/problems/convert-bst-to-greater-tree/
// Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

/*Short Explanation -
Greater Tree is such that every key of the original BST is changed to
the original key plus sum of all keys greater than the original key in BST.
Hence for a particular node, all nodes containing values greater than it should be
initially visited so that we can keep a track of their sum.

Hence we need a traversal that follows : [right, current, left] recursively.
This is exactly reverse of inorder traversal.
So we do a rev_inorder traversal and maintain sum of nodes visited till now
and utilise it to modify current node value.
*/

class Solution {
public:
    int sum = 0;
    void rev_inorder(TreeNode* root) {
        if (root == NULL)return;
        rev_inorder(root->right);
        root->val = sum += root->val;
        rev_inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        rev_inorder(root);
        return root;
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
