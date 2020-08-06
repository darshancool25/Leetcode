// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

/*
Short Explaination : Run a BFS on the binary tree and reverse every alternate level
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        if (root != NULL)q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            while (sz--) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != NULL)q.push(temp->left);
                if (temp->right != NULL)q.push(temp->right);
                level.push_back(temp->val);
            }
            if (ans.size() & 1)reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        return ans;
    }
};
