// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tail = NULL;
        ListNode *begin = head;
        ListNode *newHead = NULL;
        int n = 0;
        
        if (head == NULL || head->next == NULL)
            return head;
        // count number of nodes
        for (ListNode *curr = head; curr; curr = curr->next) {
            n++;
            tail = curr;
        }
        k %= n;
        // no-op
        if (k == 0)
            return head;
        // find new head
        ListNode *prev = NULL;
        for (int i = 0; i < n - k; i++) {
            prev = begin;
            begin = begin->next;
        }
        if (prev)
            prev->next = NULL;
        tail->next = head;
        newHead = begin;
        return newHead;
    }
};
