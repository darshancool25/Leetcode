// https://leetcode.com/problems/validate-binary-search-tree/

/* Short Explanation -
each node can only lie in a specific range, i.e [l,r]
The root can ofcourse lie in any range so initially :
l = LLONG_MIN , r = LLONG_MAX
and based on the the BST traversal we update the [l,r] parameters
passed to the function.
eg :                (156) [LLONG_MIN, LLONG_MAX]
                     /\
                    /  \
 [LLONG_MIN, 155](25)   (200)  [157 , LLONG_MAX]
*/

class Solution {
public:
    bool valid = true;
    void dfs(TreeNode* root, long long int l, long long int r) {
        if (!valid or root == NULL)return;
        if (!(root->val >= l and root->val <= r)) {
            valid = false;
            return;
        }
        dfs(root->left, l, (long long)root->val - 1);
        dfs(root->right, (long long)root->val + 1, r);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root, LLONG_MIN, LLONG_MAX);
        return valid;
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
