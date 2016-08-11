// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> s;
    stack<int> m;

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (m.empty())
            m.push(x);
        else
            m.push(min(m.top(), x));
    }
    
    void pop() {
        s.pop();
        m.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
