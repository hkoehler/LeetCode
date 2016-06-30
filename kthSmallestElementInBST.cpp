// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    stack<TreeNode*> s;

    void pushAll(TreeNode *node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        
        pushAll(root);
        while (!s.empty()) {
            auto node = s.top();
            
            s.pop();
            if (++c == k)
                return node->val;
            pushAll(node->right);
        }
        return 0;
    }
};
