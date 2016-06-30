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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        list<pair<TreeNode*, int>> queue;
        vector<vector<int>> ret;
        vector<int> level;
        int currLevel = 0;
        
        if (!root)
            return ret;
        queue.push_back(make_pair(root, 1));
        while (!queue.empty()) {
            pair<TreeNode*, int> n = queue.front();
            
            queue.pop_front();
            if (n.second != currLevel) {
                if (!level.empty())
                    ret.insert(ret.begin(), level);
                level = {};
                currLevel = n.second;
            }
            level.push_back(n.first->val);
            if (n.first->left)
                queue.push_back(make_pair(n.first->left, n.second+1));
            if (n.first->right)
                queue.push_back(make_pair(n.first->right, n.second+1));
        }
        if (!level.empty())
            ret.insert(ret.begin(), level);
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode *node, int level) {
        if (res.size() == level)
            res.push_back({});

        res[level].push_back(node->val);
        if (node->left)
            dfs(node->left, level+1);
        if (node->right)
            dfs(node->right, level+1);
    }    

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        
        if (root)
            dfs(root, 0);
        ret.insert(ret.begin(), res.rbegin(), res.rend());
        return ret;
    }
};

