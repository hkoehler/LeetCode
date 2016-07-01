// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *curr;
public:
    TreeNode *convert(ListNode *begin, int len) {
        TreeNode *treeNode = nullptr;
        
        if (len != 0) {
            treeNode = new TreeNode(0);
            treeNode->left = convert(begin, len / 2);
            treeNode->val = curr->val;
            curr = curr->next;
            treeNode->right = convert(curr, len - len / 2 - 1);
        }
        return treeNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        
        if (!head)
            return nullptr;
        for (curr = head; curr; curr = curr->next) {
            len++;
        }
        curr = head;
        return convert(head, len);
    }
};
