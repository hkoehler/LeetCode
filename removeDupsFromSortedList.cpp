// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head;
        
        if (head)
            for (ListNode *curr = head->next; curr; curr = curr->next) {
                if (curr->val == prev->val)
                    prev->next = curr->next;
                else
                    prev = curr;
            }
        return head;
    }
};
