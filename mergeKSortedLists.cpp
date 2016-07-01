//! https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> heap;
        ListNode *res = nullptr;
        ListNode *rear = nullptr;
        
        auto compare = [] (ListNode *lhs, ListNode *rhs) {
            return lhs->val > rhs->val;
        };
        
        // fill heap
        for (auto list : lists)
            if (list)
                heap.push_back(list);
        make_heap(heap.begin(), heap.end(), compare);
        
        while (!heap.empty()) {
            ListNode *node;
            
            // remove min element
            pop_heap(heap.begin(), heap.end(), compare);
            node = heap.back();
            if (rear)
                rear = rear->next = node;
            else
                rear = res = node;
            // insert next list node or shrink heap
            if (node->next) {
                heap.back() = node->next;
                push_heap(heap.begin(), heap.end(), compare);
            } else
                heap.pop_back();
        }
        return res;
    }
};
