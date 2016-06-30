// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> path;
    
    void bfs(TreeNode *root) {
        std::queue<pair<TreeNode*, int>> queue;
        
        queue.push(make_pair(root, 0));
        while (!queue.empty()) {
            auto elem = queue.front();
            auto node = elem.first;
            auto depth = elem.second;

            queue.pop();
            path.resize(depth+1);
            path[depth] = node->val;
            if (node->left)
                queue.push(make_pair(node->left, depth+1));
            if (node->right)
                queue.push(make_pair(node->right, depth+1));
        }
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root)
            bfs(root);
        return path;
    }
};
