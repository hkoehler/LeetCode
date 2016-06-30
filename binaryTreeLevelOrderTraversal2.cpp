// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<pair<TreeNode *, int>> q;
        vector<vector<int>> res;
        
        if (root)
            q.push_back(make_pair(root, 0));
        while (!q.empty()) {
            auto elem = q.front();
            auto depth = elem.second;
            auto node = elem.first;
            
            q.pop_front();
            if (res.size() <= depth)
                res.push_back({});
            res[depth].push_back(node->val);
            if (node->left)
                q.push_back(make_pair(node->left, depth+1));
            if (node->right)
                q.push_back(make_pair(node->right, depth+1));
        }
        return res;
    }
};
