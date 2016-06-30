// https://leetcode.com/problems/count-complete-tree-nodes/

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
    // return max path/height
    int height(TreeNode *node) {
        int h = 0;
        
        while (node) {
            node = node->left;
            h++;
        }
        return h;
    }
    
    // traverse using path encoded as int
    bool traverse(TreeNode *node, long long path, int height) {
        int h = 0;
        
        for (int i = height - 2; i >= 0; i--) {
            if (path & (1 << i))
                node = node->right;
            else
                node = node->left;
            if (!node)
                return false;
        }
        return true;
    }

    int countNodes(TreeNode* root) {
        long long begin = 0;
        long long end = 0;
        int height;
        
        // measure height for search space
        height = this->height(root);
        if (height == 0)
            return 0;
        for (int i = 0; i < height - 1; i++)
            end |= (0x1 << i);
        //cout << "height " << height << " end " << hex << end << endl;
        
        /*for (int i = begin; i <= end; i++)
            if (!traverse(root, i, height)) {
                end = i - 1;
                break;
            }*/
        
        while (begin < end) {
            // search for lower bound
            long long m = begin + (end - begin + 1) / 2;
            if (traverse(root, m, height))
                begin = m;      // include m
            else
                end = m - 1;    // don't include m
        }
        //cout << "path " << hex << end << endl;
        
        // count complete part of tree
        int count = 0;
        int levelCount = 1;
        for (int i = 1; i <= height - 1; i++) {
            count += levelCount;
            levelCount *= 2;
        }
        // count incomplete part of tree
        count += begin + 1;
        
        return count;
    }
};
