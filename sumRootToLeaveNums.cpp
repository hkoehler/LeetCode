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
    int visit(TreeNode *node, vector<int> nums) {
        int ret = 0;
        
        nums.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            int multiplier = 1;
            for (auto n = nums.rbegin(); n != nums.rend(); n++) {
                ret += *n * multiplier;
                multiplier *= 10;
            }
            return ret;
        } else if (node->left && node->right)
            return visit(node->left, nums) + visit(node->right, nums);
        else if (node->left)
            return visit(node->left, nums);
        return visit(node->right, nums);
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        
        if (root)
            return visit(root, nums);
        return 0;
    }
};

