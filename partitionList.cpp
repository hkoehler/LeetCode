// https://leetcode.com/problems/partition-list/

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
    ListNode *listAppend(ListNode *rear, ListNode *item) {
        rear->next = item;
        return item;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode lesserHead(0);
        ListNode greaterHead(0);
        ListNode *lesserRear = &lesserHead;
        ListNode *greaterRear = &greaterHead;
        
        if (!head)
            return NULL;
        for (ListNode *curr = head; curr; curr = curr->next)
            if (curr->val < x)
                lesserRear = listAppend(lesserRear, curr);
            else
                greaterRear = listAppend(greaterRear, curr);
        greaterRear->next = NULL;
        lesserRear->next = greaterHead.next;
        return lesserHead.next;
    }
};
