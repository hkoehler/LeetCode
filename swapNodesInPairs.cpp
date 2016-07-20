// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret = NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        if (head == NULL || head->next == NULL)
            return head;
        while (curr) {
            ListNode *next = curr->next;
            
            curr->next = NULL;
            if (prev)
                prev->next = next ? next : curr;
            else
                ret = next;
            if (next == NULL)
                break;
            prev = curr;
            swap(curr, next->next);
        }
        return ret;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        ListNode *next;
        ListNode **pNext = &head;

        while (curr && (next = curr->next)) {
            // update head or next pointer
            *pNext = next;
            pNext = &curr->next;
            curr->next = next->next;
            next->next = curr;
            curr = curr->next;
        }
        return head;
    }
};
