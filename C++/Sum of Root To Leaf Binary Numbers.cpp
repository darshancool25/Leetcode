// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/


class Solution {
public:
    int ans = 0;
    void traverse(TreeNode* root, string s) {
        if (root == NULL)return;
        s += (char)(root->val + '0');
        if (root->right == NULL and root->left == NULL) {
            int deci = 0;
            for (int i = 0; i < s.length(); i++)
                deci += (s[i] == '1' ? (1 << (s.length() - i - 1)) : (0));
            ans += deci;
            return;
        }
        traverse(root->right, s);
        traverse(root->left, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");
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
