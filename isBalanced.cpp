// https://leetcode.com/problems/balanced-binary-tree/

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
    int dfs(TreeNode *node, bool &balanced) {
        int leftDepth = 0, rightDepth = 0;
        if (!node)
            return 0;
        leftDepth = dfs(node->left, balanced);
        if (!balanced)
            return 0;
        rightDepth = dfs(node->right, balanced);
        if (!balanced)
            return 0;
        if (abs(leftDepth - rightDepth) > 1)
            balanced = false;
        return max(leftDepth, rightDepth) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        
        dfs(root, balanced);
        return balanced;
    }
};
