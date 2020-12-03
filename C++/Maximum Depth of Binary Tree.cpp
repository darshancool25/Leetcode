// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/*Short Explanation :
Apply DFS on tree, keep track of max depth */

class Solution {
public:
    int depth = 0;
    void dfs(TreeNode* root, int d) {
        if (root == NULL)return;
        depth = max(depth, d + 1);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return depth;
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
