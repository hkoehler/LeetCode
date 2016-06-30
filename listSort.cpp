// https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        size_t size = 0;
        
        if (!head)
            return head;
        for (ListNode *curr = head; curr; curr = curr->next) {
            size++;
            //cout << curr->val << " ";
        }
        //cout << " size=" << size << endl;
        if (size == 1)
            return head;
        if (size == 2) {
            ListNode *tmp = head->next;
            if (head->val > tmp->val) {
                head->next = NULL;
                tmp->next = head;
                return tmp;
            }
            return head;
        }
        
        // split list into halves
        ListNode *prev = NULL;
        ListNode *head2 = NULL;
        int i = 0;
        
        for (ListNode *curr = head; curr; prev = curr, curr = curr->next, i++) {
            if (i == size / 2) {
                prev->next = NULL;
                head2 = curr;
                break;
            }
        }
        
        // merge lists
        ListNode *curr1 = sortList(head);
        ListNode *curr2 = sortList(head2);
        ListNode *curr = NULL;
        ListNode *h = NULL;
        
        for (;;) {ps6dw
        
            if (curr1 == NULL && curr2 == NULL) {
                curr->next = NULL;
                break;
            }
            if (curr1 == NULL) {
                curr->next = curr2;
                break;
            }
            if (curr2 == NULL) {
                curr->next = curr1;
                break;
            }
            if (curr1->val < curr2->val) {
                if (curr == NULL)
                    h = curr = curr1;
                else {
                    curr->next = curr1;
                    curr = curr1;
                }
                curr1 = curr1->next;
            } else {
                if (curr == NULL)
                    h = curr = curr2;
                else {
                    curr->next = curr2;
                    curr = curr2;
                }
                curr2 = curr2->next;
            }
        }
        return h;
    }
};
