// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *prevNode = nullptr;
        size_t prevDepth = 0;
        queue<pair<TreeLinkNode*, size_t>> q;
        
        if (root)
            q.push(make_pair(root, 1));
        while (!q.empty()) {
            auto qe = q.front();
            auto node = qe.first;
            auto depth = qe.second;
            
            q.pop();
            if (prevDepth == depth)
                prevNode->next = node;
            if (node->left)
                q.push(make_pair(node->left, depth+1));
            if (node->right)
                q.push(make_pair(node->right, depth+1));
            prevNode = node;
            prevDepth = depth;
        }
    }
};
