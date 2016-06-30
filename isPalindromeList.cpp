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
    bool isPalindrome(ListNode* head) {
        size_t len = 0;
        ListNode *curr = nullptr;
        ListNode *curr2 = nullptr;
        ListNode *reverse = nullptr;
        ListNode *tmp = nullptr;
        int i = 0;
        
        if (!head)
            return true;
        for (curr = head; curr; curr = curr->next)
            len++;
        if (len == 1)
            return true;
        for (curr = head, i = 0; i < len / 2; curr = tmp, i++) {
            tmp = curr->next;
            if (reverse == nullptr) {
                reverse = curr;
                curr->next = nullptr;
            } else {
                curr->next = reverse;
                reverse = curr;
            }
        }
        if (len % 2 == 1)
            tmp = tmp->next;
        for (curr = reverse, curr2 = tmp; curr && curr2; curr = curr->next, curr2 = curr2->next)
            if (curr->val != curr2->val)
                return false;
        return curr == nullptr && curr2 == nullptr;
    }
};
