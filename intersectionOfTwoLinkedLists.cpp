#include <cassert>
#include <unistd.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
    size_t listLen(ListNode *head) {
        size_t len = 0;
        
        for (ListNode *curr = head; curr; curr = curr->next)
            len++;
        return len;
    }
    
    ListNode *advance(ListNode *head, size_t count) {
        for (ListNode *curr = head; curr; curr = curr->next)
            if (count-- == 0)
                return curr;
        return nullptr;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lenA, lenB;
        ListNode *a = headA, *b = headB;
        
        lenA = listLen(headA);
        lenB = listLen(headB);
        if (lenA > lenB)
            a = advance(a, lenA - lenB);
        if (lenB > lenA)
            b = advance(b, lenB - lenA);
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};

void run(ListNode *a, ListNode *b, ListNode *c) {
    Solution sol;
    ListNode *res;
    
    res = sol.getIntersectionNode(a, b);
    assert(res == c);
}

void test1() {
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(1);
    ListNode b2(2);
    ListNode b3(3);
    ListNode c1(1);
    ListNode c2(2);
    ListNode c3(3);
    
    a1.next = &a2;
    a2.next = &c1;
    
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    c1.next = &c2;
    c2.next = &c3;
    run(&a1, &b1, &c1);    
}

void test2() {
    run(nullptr, nullptr, nullptr);
}

void test3() {
    ListNode a(0);
    ListNode b(0);
    run(&a, &b, nullptr);
}

int main(int argc, char *argv[]) {
    test1();
    test2();
    test3();
    return 0;
}

