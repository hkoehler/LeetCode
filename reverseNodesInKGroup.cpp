//! https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    // fetch current KGroup and terminate list
    // return next KGoup head in ppNextKGroup
    bool fetchKGroup(ListNode *head, int k, ListNode **ppNextKGroup) {
        ListNode *curr = head;
        ListNode *rear = NULL;

        for (int i = 0; i < k; i++) {
            if (!curr) {
                *ppNextKGroup = NULL;
                return false; // less than k nodes
            }
            rear = curr;
            curr = curr->next;
        }
        *ppNextKGroup = rear->next;
        rear->next = NULL; // terminate k nodes list
        return true;
    }

    // revert any list
    ListNode *reverseList(ListNode *head) {
        ListNode *last = NULL;
        ListNode *curr = head;
        
        while (curr) {
            auto tmp = curr->next;
            curr->next = last;
            last = curr;
            curr = tmp;
        }
        return last;
    }

    ListNode *reverseKGroup(ListNode* head, int k) {
        ListNode **pp = &head;
        ListNode *nextKGroup;
        ListNode *kGroup = head;

        if (!head || k < 2)
            return head;
        while (fetchKGroup(kGroup, k, &nextKGroup)) {
            // update previous next pointer
            *pp = reverseList(kGroup);
            pp = &kGroup->next;
            kGroup = nextKGroup;
        }
        *pp = kGroup;
        return head;
    }
};
