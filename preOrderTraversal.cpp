// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> res;
        
        if (root)
            s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->right)
                s.push(node->right);
            // push left last to be popped next
            if (node->left)
                s.push(node->left);
        }
        return res;
    }
};
