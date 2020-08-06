// https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;

        queue<pair<TreeNode*,  unsigned long long>> q;
        if (root)
            q.push({root, 1});

        while (!q.empty()) {
            int cnt = q.size();
            unsigned long long left = q.front().second, right;
            for (int i = 0; i < cnt; i++) {
                TreeNode* n = q.front().first;
                right = q.front().second;
                q.pop();
                if (n->left != nullptr) {
                    q.push({n->left, 2 * right});
                }
                if (n->right != nullptr) {
                    q.push({n->right, 2 * right + 1});
                }
            }
            ans = max(ans, (int)(right - left + 1));
        }

        return ans;
    }
};
