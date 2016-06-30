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

    struct MyNode {
        MyNode(int v) : val(v), left(nullptr), right(nullptr), sum(0), childSum(0) {}
        int val;
        int sum;
        int childSum;
        MyNode *left;
        MyNode *right;
    } *root;

    MyNode *init(TreeNode *node) {
        auto n = new MyNode(node->val);
        
        if (node->left)
            n->left = init(node->left);
        if (node->right)
            n->right = init(node->right);
        return n;
    }

    void solve(MyNode *node) {
        int childChildSum = 0;
        
        if (node->left) {
            solve(node->left);
            node->childSum += node->left->sum;
            childChildSum += node->left->childSum;
        }
        if (node->right) {
            solve(node->right);
            node->childSum += node->right->sum;
            childChildSum += node->right->childSum;
        }
        node->sum = max(node->val + childChildSum, node->childSum);
    }

    int rob(TreeNode* root) {
        if (!root)
            return 0;
        auto myRoot = init(root);
        solve(myRoot);
        return myRoot->sum;
    }
};
