// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
 
 // Recursive Solution
class Solution {
public:
        
    TreeNode* tree(vector<int>& in,int in_l, int in_r, vector<int>& post, int post_l, int post_r){
        if((in_l > in_r) or (post_l>post_r))return NULL;
        TreeNode* node = new TreeNode(post[post_r]);
        int x = in_l;
        while(node->val != in[x])x++;
        node->left = tree(in,in_l,x-1,post,post_l,post_l+x-in_l-1);
        node->right = tree(in,x+1,in_r,post,post_l+x-in_l,post_r-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return tree(in,0,in.size()-1,post,0,post.size()-1);
    }
};
