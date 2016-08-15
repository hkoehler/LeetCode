#include <stack>
#include <cassert>

using namespace std;

class Queue {
    stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        tmp.pop();
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> tmp;
        int res;
        
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        res = tmp.top();
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};

int main(void) {
    Queue q;
    
    assert(q.empty());
    q.push(1);
    assert(q.peek() == 1);
    q.push(2);
    assert(q.peek() == 1);
    q.pop();
    assert(q.peek() == 2);
    q.push(3);
    assert(q.peek() == 2);
    q.pop();
    assert(q.peek() == 3);
    q.pop();
    assert(q.empty());
    return 0;
}
