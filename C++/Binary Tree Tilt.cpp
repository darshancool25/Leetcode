// https://leetcode.com/problems/binary-tree-tilt/

/*Short Explanation :
For each node calculate sum of its subtree, by using a DFS.
Now for each node, ans += abs(dfs(left_node) + dfs(right_node)).
NOTE : dfs(node) returns the subtree_sum of 'node'.
*/

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        int l = 0, r = 0;
        if (root->left != NULL)l = dfs(root->left);
        if (root->right != NULL)r = dfs(root->right);
        ans += abs(r - l);
        root->val += l + r;
        return root->val;
    }

    int findTilt(TreeNode* root) {
        if (root != NULL)dfs(root);
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
