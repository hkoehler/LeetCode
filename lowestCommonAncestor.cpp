/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, int> visited;
    TreeNode *lca = nullptr;

    bool dfs(TreeNode *n, TreeNode *p) {
        bool found = false;
        
        if (n == p)
            found = true;
        if (n->left && found == false)
            found = dfs(n->left, p);
        if (n->right && found == false)
            found = dfs(n->right, p);
        if (found) {
            visited[n]++;
            if (visited[n] == 2 && lca == nullptr)
                lca = n;
        }
        return found;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p);
        dfs(root, q);
        return lca;
    }
};
