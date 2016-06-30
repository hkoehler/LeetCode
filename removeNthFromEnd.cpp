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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        ListNode *toRemove = nullptr;
        ListNode *prev = nullptr;
        
        if (!head)
            return head;
        for (int i = 0; i < n; i++) {
            curr = curr->next;
        }
        toRemove = head;
        while (curr) {
            prev = toRemove;
            toRemove = toRemove->next;
            curr = curr->next;
        }
        if (prev) {
            if (toRemove)
                prev->next = toRemove->next;
            return head;
        } else {
            return head->next;
        }
    }
};

