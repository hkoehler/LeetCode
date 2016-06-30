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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lesser = nullptr;
        ListNode *lesserRear = nullptr;
        ListNode *greater = nullptr;
        ListNode *greaterRear = nullptr;

        for (ListNode *curr = head; curr; curr = curr->next)
            if (curr->val < x) {
                if (lesser) {
                    lesserRear->next = curr;
                    lesserRear = curr;
                } else {
                    lesser = curr;
                    lesserRear = curr;
                }
            } else {
                if (greater) {
                    greaterRear->next = curr;
                    greaterRear = curr;
                } else {
                    greater = curr;
                    greaterRear = curr;
                }
            }
        if (lesserRear)
            lesserRear->next = greater;
        else
            return greater;
        return lesser;
    }
};

