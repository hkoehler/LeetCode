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
    bool hasCycle(ListNode *head) {
        ListNode *n1 = head;
        ListNode *n2 = head;

        if (head == nullptr)
            return false;
        for (;;) {
            n1 = n1->next;
            if (n1 == nullptr)
                return false;
            n2 = n2->next;
            if (n2 == nullptr)
                return false;
            n2 = n2->next;
            if (n2 == nullptr)
                return false;
            if (n1 == n2)
                return true;
        }
    }
};

