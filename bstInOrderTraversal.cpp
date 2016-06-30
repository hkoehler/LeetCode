// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void traverseLeft(TreeNode *node, stack<TreeNode *> &s) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> res;

        traverseLeft(root, s);
        while (!s.empty()) {
            TreeNode *node = s.top();
            
            s.pop();
            res.push_back(node->val);
            traverseLeft(node->right, s);
        }
        return res;
    }
};
