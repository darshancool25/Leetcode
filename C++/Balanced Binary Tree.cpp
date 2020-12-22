// https://leetcode.com/problems/balanced-binary-tree/

/*Short Explanation -
Calculate height of each node as required in the question.
(Store height in node->val as node values are of no use to us anyways !!)
i.e leaf nodes have height 0.
Now the above task can be done while running a DFS in the tree.
After applying dfs(root->right), dfs(root->left) check for the
balanced tree condition by checking absolute difference of height of both childs.
If at any point, tree is unbalanced, stop the DFS and return.
*/

class Solution {
public:
    bool balanced = true;
    void dfs(TreeNode* root) {
        if (!balanced or root == NULL)return;
        dfs(root->left);
        dfs(root->right);
        int l = 0, r = 0;
        if (root->left != NULL)l = root->left->val;
        if (root->right != NULL)r = root->right->val;
        if (abs(l - r) > 1)balanced = false;
        root->val = max(l + 1, r + 1);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
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
