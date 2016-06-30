// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ (105)

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
    map<int, TreeNode*> nodes;
    
    TreeNode *lookup(int val) {
        auto iter = nodes.find(val);
        if (iter != nodes.end())
            return iter->second;
        auto n = new TreeNode(val);
        nodes[val] = n;
        return n;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // find root in preorder
        while (preorder.size() > 1)
            for (int i = 0; i < preorder.size(); i++) {
                if (i + 2 >= preorder.size())
                    break;
                int root = preorder[i];
                int left = preorder[i+1];
                int right = preorder[i+2];
                
                // find root in inorder
                bool found = false;
                for (int j = 1; j < inorder.size(); j++) {
                    if (j + 1 >= inorder.size())
                        break;
                    if (inorder[j] == root && inorder[j-1] == left && inorder[j+1] == right) {
                        auto rootNode = lookup(root);
                        rootNode->left = lookup(left);
                        rootNode->right = lookup(right);
                        inorder.erase(inorder.begin() + j + 1);
                        inorder.erase(inorder.begin() + j - 1);
                        found = true;
                        break;
                    }
                }
                if (found) {
                    preorder.erase(preorder.begin() + i + 2);
                    preorder.erase(preorder.begin() + i + 1);
                }
            }
        return preorder.empty() ? nullptr : lookup(preorder.back());
    }
};

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
    map<int, TreeNode*> nodes;
    
    TreeNode *lookup(int val) {
        auto iter = nodes.find(val);
        if (iter != nodes.end())
            return iter->second;
        auto n = new TreeNode(val);
        nodes[val] = n;
        return n;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> preorder1, preorder2, inorder1, inorder2;
        TreeNode *rootNode = nullptr;
        
        if (preorder.empty())
            return nullptr;
        if (preorder.size() == 1)
            return lookup(preorder[0]);
        
        int root = preorder[0];
        rootNode = lookup(root);
        bool found = false;
        for (int i = 0, j = 1; i < inorder.size(); i++) {
            if (inorder[i] == root)
                found = true;
            else if (found) {
                inorder2.push_back(inorder[i]);
                preorder2.push_back(preorder[j++]);
            } else {
                inorder1.push_back(inorder[i]);
                preorder1.push_back(preorder[j++]);
            }
        }
        rootNode->left = buildTree(preorder1, inorder1);
        rootNode->right = buildTree(preorder2, inorder2);
        return rootNode;
    }
};

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
    map<int, TreeNode*> nodes;
    
    TreeNode* buildTree(vector<int>::iterator preorderBegin,
                        vector<int>::iterator preorderEnd,
                        vector<int>::iterator inorderBegin,
                        vector<int>::iterator inorderEnd) {
        TreeNode *rootNode = nullptr;
        size_t len = distance(preorderBegin, preorderEnd);

        if (len == 0)
            return nullptr;
        if (len == 1)
            return new TreeNode(*preorderBegin);
        
        int root = *preorderBegin;
        rootNode = new TreeNode(root);
        auto inorderRoot = find(inorderBegin, inorderEnd, root);
        size_t leftLen = distance(inorderBegin, inorderRoot);
        rootNode->left = buildTree(preorderBegin+1, preorderBegin+1+leftLen,
                                   inorderBegin, inorderBegin+leftLen);
        rootNode->right = buildTree(preorderBegin+1+leftLen, preorderEnd,
                                    inorderRoot+1, inorderEnd);
        return rootNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
