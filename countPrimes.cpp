//! https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        set<int> primes;
        
        primes.insert(2);
        for (int i = 3; i < n; i += 2) {
            bool isPrime = true;
            for (auto prime : primes)
                if (i % prime == 0) {
                    isPrime = false;
                    break;
                }
            if (isPrime)
                primes.insert(i);
        }
        return primes.size();
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n);

        // mark off 0 and 1
        nums[0] = true;
        nums[1] = true;
        
        // mark off multiples of i starting at i*i
        for (int i = 0; i * i < n; i++)
            if (nums[i] == false)
                for (int j = i * i; j <= n; j += i)
                    nums[j] = true;

        // count numbers not marked off
        int count = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == false)
                count++;
        return count;
    }
};
