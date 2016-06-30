// https://leetcode.com/problems/add-two-numbers/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carryBit = false;
        ListNode *rear = nullptr;
        ListNode *l3 = nullptr;
        
        while (l1 || l2 || carryBit) {
            int n1 = 0, n2 = 0, n3 = 0;
            
            if (l1) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                n2 = l2->val;
                l2 = l2->next;
            }
            n3 = n1 + n2 + (carryBit ? 1 : 0);
            carryBit = (n3 >= 10);
            auto node = new ListNode(n3 % 10);
            if (l3 == nullptr)
                l3 = node;
            else 
                rear->next = node;
            rear = node;
        }
        return l3;
    }
};

