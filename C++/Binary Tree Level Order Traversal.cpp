// https://leetcode.com/problems/binary-tree-level-order-traversal/

/*Short Explanation -
Run a BFS (level order traversal) and store level wise node values.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)return ans;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> curr_level;
            while (sz--) {
                TreeNode* temp = q.front(); q.pop();
                curr_level.push_back(temp->val);
                if (temp->left)q.push(temp->left);
                if (temp->right)q.push(temp->right);
            }
            ans.push_back(curr_level);
        }
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
