// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    enum State {LEFT, RIGHT, ROOT};
    struct StackFrame {
        TreeNode *node;
        State state;
    };
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<StackFrame> s;

        if (root)
            s.push({root, LEFT});
        while (!s.empty()) {
            StackFrame &f = s.top();
            TreeNode *node = f.node;
            
            switch (f.state) {
            case LEFT:
                f.state = RIGHT;
                if (node->left) {
                    s.push({node->left, LEFT});
                    break;
                }
            // fall-through
            case RIGHT:
                f.state = ROOT;
                if (f.node->right) {
                    s.push({node->right, LEFT});
                    break;
                }
            // fall-through
            case ROOT:
                res.push_back(node->val);
                s.pop();
                break;
            default:
                assert(0);
            }
        }
        return res;
    }
};

