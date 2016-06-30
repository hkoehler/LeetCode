// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> m;
        size_t total = 1;

        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        // 1 is ugly
        m.insert(1);
        for (int i = 2;; i++) {
            if (i % 2 == 0 && m.find(i/2) != m.end() ||
                i % 3 == 0 && m.find(i/3) != m.end() ||
                i % 5 == 0 && m.find(i/5) != m.end()) {
                    if (++total == n)
                        return i;
                    else
                        m.insert(i);
                }
        }
        return -1;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> m;
        int curr = 1;

        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        // 1 is ugly
        m.insert(1);
        for (int i = 2; i <=  n; i++) {
            int next = numeric_limits<int>::max();
            // next ugly number is min(m) * either 2, 3 or 5
            for (auto x : m) {
                if (x * 2 > curr)
                    next = min(next, x * 2);
                if (x * 3 > curr)
                    next = min(next, x * 3);
                if (x * 5 > curr)
                    next = min(next, x * 5);
            }
            //cout << "insert " << next << endl;
            m.insert(next);
            curr = next;
        }
        return curr;
    }
};

// accepted solution
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> m;
        long long curr = 1;
        int total = 0;

        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        // 1 is ugly
        m.insert(1);
        for (;;) {
            curr = *m.begin();
            m.erase(curr);
            if (++total == n)
                break;
            // generate new potential subsequent ugly numbers
            m.insert(curr * 2);
            m.insert(curr * 3);
            m.insert(curr * 5);
        }
        return curr;
    }
};
