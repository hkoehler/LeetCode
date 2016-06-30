// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool dfs(TreeNode *node, long &min, long &max) {
        long leftMin = LONG_MAX, leftMax = LONG_MIN;
        long rightMin = LONG_MAX, rightMax = LONG_MIN;
        bool ret;
        
        if (!node)
            return true;
        
        ret = dfs(node->left, leftMin, leftMax) &&
              dfs(node->right, rightMin, rightMax);
        if (ret == false || leftMax >= node->val || rightMin <= node->val)
            ret = false;

        min = std::min(min, (long)node->val);
        min = std::min(min, leftMin);
        min = std::min(min, rightMin);
        
        max = std::max(max, (long)node->val);
        max = std::max(max, leftMax);
        max = std::max(max, rightMax);

        return ret;
    }

    bool isValidBST(TreeNode* root) {
        long min = LONG_MAX, max = LONG_MIN;
        return dfs(root, min, max);
    }
};
