// https://leetcode.com/problems/average-of-levels-in-binary-tree/

/*Short Explanation -
    Run a BFS (level order traversal) on tree,
    maintain 'sum' of each level.
    Average of level is = sum / dsz
    where 'dsz' is the number of nodes in the level (double data type)
*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            double sum = 0, dsz = sz;
            while (sz--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)q.push(temp->left);
                if (temp->right)q.push(temp->right);
            }
            ans.push_back(sum / dsz);
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
