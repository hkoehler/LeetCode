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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *curr = head, *tmp = nullptr, *rHead, *rRear, *lRear = nullptr;
        
        assert(m <= n);
        assert(m >= 1);
        assert(n >= 1);
        for (int i = 1; curr; i++) {
            tmp = curr->next;
            if (i == m - 1) {
                lRear = curr;
                lRear->next = nullptr;
            } else if (i == m) {
                rHead = rRear = curr;
                rRear->next = nullptr;
            }
            if (i > m && i <= n) {
                curr->next = rHead;
                rHead = curr;
            } 
            if (i == n) {
                rRear->next = tmp;
                if (lRear)
                    lRear->next = rHead;
                else
                    head = rHead;
                break;
            }
            assert(i <= n);
            curr = tmp;
        }
        return head;
    }
};

