// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/*Short Explanation -
do a dfs on original tree (searching for target node), but at same time
travel in same fashion in the cloned tree as well. Once target node is found
end dfs, and return the corresponding node in cloned tree.
*/

class Solution {
public:
    TreeNode *res;
    bool found = false;
    void dfs(TreeNode* node, TreeNode* node2, TreeNode* target) {
        if (found or node == NULL)return;
        if (node == target) {
            found = true;
            res = node2;
            return;
        }
        dfs(node->right, node2->right, target);
        dfs(node->left, node2->left, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original, cloned, target);
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
