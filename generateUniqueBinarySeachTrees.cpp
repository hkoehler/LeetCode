// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    // map (begin, end) to vector of TreeNode*
    vector<vector<vector<TreeNode *>>> dp;
public:

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};

        dp.resize(n+1);
        for (auto &e : dp)
            e.resize(n+1);
        
        // start with smallest size
        for (int size = 1; size <= n; size++) {
            // pick start of range
            for (int begin = 1; begin <= n - size + 1; begin++) {
                int end = begin + size - 1;
                // pick root in range
                for (int r = begin; r <= end; r++) {
                    // all possible left and right subtrees
                    vector<TreeNode*> leftTrees, rightTrees;
                    
                    if (r > begin)
                        leftTrees = dp[begin][r-1];
                    else
                        leftTrees.push_back(nullptr);
                    if (r < end)
                        rightTrees = dp[r+1][end];
                    else
                        rightTrees.push_back(nullptr);
                    // combine all possible left and right subtrees
                    for (auto leftTree : leftTrees)
                        for (auto rightTree : rightTrees) {
                            auto node = new TreeNode(r);
                            node->left = leftTree;
                            node->right = rightTree;
                            dp[begin][end].push_back(node);
                        }
                }
            }
        }

        return dp[1][n];
    }
};
