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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ret = nullptr;
        ListNode *tmp = nullptr;
        ListNode *retRear = nullptr;
        int val;
        int n = 0;

        if (!head)
            return head;
        if (head->next == nullptr)
            return head;

        for (ListNode *curr = head; curr; curr = curr->next) {
            // new value
            if (n == 0) {
                val = curr->val;
                tmp = curr;
                n++;
            // duplicate value
            } else if (curr->val == val) {
                tmp = nullptr;
                n++;
            // new value, queue previous item
            } else {
                if (tmp) {
                    if (!ret)
                        ret = tmp;
                    else
                        retRear->next = tmp;
                    retRear = tmp;
                }
                val = curr->val;
                tmp = curr;
                n = 1;
            }
        }
        if (tmp && n == 1) {
            if (!ret)
                ret = tmp;
            else
                retRear->next = tmp;
            retRear = tmp;
        }
        if (retRear)
            retRear->next = nullptr;
        return ret;
    }
};

