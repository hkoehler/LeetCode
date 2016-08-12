// https://leetcode.com/problems/sliding-window-maximum/

template <typename T>
class MonoQueue {
    deque<T> q;
    deque<T> maxQ;
public:
    void push(T n) {
        // maxQ is monotonically decreasing
        while (maxQ.empty() == false && maxQ.back() < n)
            maxQ.pop_back();
        maxQ.push_back(n);
        q.push_back(n);
    }
    
    void pop() {
        // pop max value if max value dequeued
        if (maxQ.front() == q.front())
            maxQ.pop_front();
        q.pop_front();
    }
    
    // report max value w/o dequeuing
    T max() {
        return maxQ.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto iter = nums.begin();
        MonoQueue<int> q;
        vector<int> res;
        
        if (nums.empty())
            return res;
        
        for (int i = 0; i < k && iter != nums.end(); i++)
            q.push(*iter++);
        
        for (;;) {
            res.push_back(q.max());
            q.pop();
            if (iter == nums.end())
                break;
            q.push(*iter++);
        }
        return res;
    }
};
