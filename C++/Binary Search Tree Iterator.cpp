// https://leetcode.com/problems/binary-search-tree-iterator/

/*Short Explanation -
Run an inorder traversal on the BST and store the values in a vector names 'val'.
Maintain a curr index which is initially set to -1.
As all next() calls are valid calls , simply return (++curr)th element from val.
to check fs there exists a next element, simply check if curr+1 is a valid index for vector val.
*/

class BSTIterator {
public:
    vector<int> val;
    int curr;
    void inorder(TreeNode* root) {
        if (root == NULL)return ;
        inorder(root->left);
        val.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        curr = -1;
    }

    int next() {
        return val[++curr];
    }

    bool hasNext() {
        return curr + 1 < val.size();
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
 *
 *
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
