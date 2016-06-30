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
    
    int totalMaxSum = INT_MIN;
    map<TreeNode *, int> maxSum;

    void dfs(TreeNode *node) {
        if (!node)
            return;
        if (!node->left && !node->right) {
            maxSum[node] = node->val;
        }
        if (node->left) {
            dfs(node->left);
            maxSum[node] = max(maxSum[node], node->val + maxSum[node->left]);
        }
        if (node->right) {
            dfs(node->right);
            maxSum[node] = max(maxSum[node], node->val + maxSum[node->right]);
        }
        if (node->left && node->right)
            maxSum[node] = max(maxSum[node], maxSum[node->left] + node->val + maxSum[node->right]);
        totalMaxSum = max(maxSum[node], totalMaxSum);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return totalMaxSum;
    }
};
