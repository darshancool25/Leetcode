// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*Short Explanation -
Run a DFS on the Tree and store the nodes level wise.
Now for each level update the next pointers of the nodes and return the root.
*/

class Solution {
public:
    vector<Node*> lvl[6005];
    int depth = 0;
    void dfs(Node* root, int d) {
        if (root == NULL)return;
        depth = max(depth, d);
        lvl[d].push_back(root);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    Node* connect(Node* root) {
        dfs(root, 0);
        for (int i = 0; i <= depth; i++) {
            for (int j = 1; j < lvl[i].size(); j++)
                (lvl[i][j - 1])->next = lvl[i][j];
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
