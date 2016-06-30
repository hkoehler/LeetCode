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
    int dfs(TreeNode *node, int depth) {
        if (node->left && node->right)
            return min(dfs(node->left, depth+1), dfs(node->right, depth+1));
        else if (node->left)
            return dfs(node->left, depth+1);
        else if (node->right)
            return dfs(node->right, depth+1);
        else
            return depth;
    }

    int minDepth(TreeNode* root) {
        if (root)
            return dfs(root, 1);
        else
            return 0;
    }
};
