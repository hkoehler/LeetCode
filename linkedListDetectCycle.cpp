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
    ListNode *detectCycle(ListNode *head) {
        ListNode *n1 = head;
        ListNode *n2 = head;
        
        if (!head)
            return nullptr;
        
        for (;;) {
            n1 = n1->next;
            if (n1 == nullptr)
                return nullptr;
            n2 = n2->next;
            if (n2 == nullptr)
                return nullptr;
            n2 = n2->next;
            if (n2 == nullptr)
                return nullptr;
            if (n1 == n2)
                break;
        }
        
        n2 = head;
        for (;;) {
            if (n1 == n2)
                return n1;
            n2 = n2->next;
            n1 = n1->next;
        }
    }
};
