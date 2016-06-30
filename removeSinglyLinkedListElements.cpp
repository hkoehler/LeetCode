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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *copy = nullptr;
        
        if (head == nullptr)
            return nullptr;
        while (curr) {
            if (curr->val != val) {
                if (copy == nullptr)
                    copy = head;
                else
                    copy = copy->next;
                copy->val = curr->val;
            }
            curr = curr->next;
        }
        if (copy)
            copy->next = nullptr;
        else
            return nullptr;
        return head;
    }
};
