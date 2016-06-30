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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *rear = nullptr;
        ListNode *head = nullptr;

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (curr1->val < curr2->val) {
            head = curr1;
            curr1 = curr1->next;
        } else {
            head = curr2;
            curr2 = curr2->next;
        }
        rear = head;

        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                rear->next = curr1;
                rear = curr1;
                curr1 = curr1->next;
            } else {
                rear->next = curr2;
                rear = curr2;
                curr2 = curr2->next;
            }
        }
        if (curr1)
            rear->next = curr1;
        else if (curr2)
            rear->next = curr2;
        else
            rear->next = nullptr;
        return head;
    }
};
