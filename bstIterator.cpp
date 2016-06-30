// https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    enum Step {LEFT, ROOT, RIGHT, UP};
    
    struct StackFrame {
        StackFrame(TreeNode *n) : node(n), step(LEFT) {}
        TreeNode *node;
        enum Step step;
    };
    stack<StackFrame> s;
public:
    BSTIterator(TreeNode *root) {
        if (root)
            s.push(StackFrame(root));
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while (!s.empty()) {
            auto &curr = s.top();
            
            switch (curr.step) {
            case LEFT:
                curr.step = ROOT;
                if (curr.node->left)
                    s.push(StackFrame(curr.node->left));
                break;
            case ROOT:
                // value can be consumed in ROOT step
                return true;
            case RIGHT:
                curr.step = UP;
                if (curr.node->right)
                    s.push(StackFrame(curr.node->right));
                break;
            case UP:
                s.pop();
                break;
            default:
                assert(0);
            }
        }
        return false;
    }

    /** @return the next smallest number */
    int next() {
        auto &curr = s.top();
        assert(curr.step == ROOT);
        curr.step = RIGHT;
        return curr.node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
