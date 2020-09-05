// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

/*
Quick Explanation -
Do inorder traversal on both trees and combine their elements in merge sort fashion.
*/

class Solution {
public:
    void inorder(TreeNode *root, vector<int>&vect) {
        if (root == NULL)return;
        inorder(root->left, vect);
        vect.push_back(root->val);
        inorder(root->right, vect);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elem1 , elem2;
        inorder(root1, elem1);
        inorder(root2, elem2);
        vector<int> ans;
        int i = 0, j = 0;
        while (i < elem1.size() and j < elem2.size()) {
            if (elem1[i] <= elem2[j])ans.push_back(elem1[i++]);
            else ans.push_back(elem2[j++]);
        }
        while (j < elem2.size())ans.push_back(elem2[j++]);
        while (i < elem1.size())ans.push_back(elem1[i++]);
        return ans;
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
