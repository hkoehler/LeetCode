// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    size_t left(size_t i) { return 2 * i + 1; }
    size_t right(size_t i) { return 2 * i + 2; }

    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int i;

        for (i = 0; i < k; i++) {
            pop_heap(nums.begin(), nums.end() - i);
        }
        return *(nums.end() - i);
    }
};

class Solution {
public:
    size_t left(size_t i) { return 2*i+1; }
    size_t right(size_t i) { return 2*i+2; }

    void push_heap(size_t off, vector<int> &nums, size_t len) {
        size_t l = left(off);
        size_t r = right(off);
        size_t m = off;
        
        if (l < len && nums[l] > nums[m])
            m = l;
        if (r < len && nums[r] > nums[m])
            m = r;
        if (m == off)
            return;
        swap(nums[m], nums[off]);
        push_heap(m, nums, len);
    }

    void heapify(vector<int>& nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; i--) {
            push_heap(i, nums, nums.size());
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        size_t len = nums.size();
        int i;
        
        heapify(nums);
        for (auto n : nums)
            cout << n << ",";
        for (i = 0; i < k; i++) {
            swap(nums[0], nums[len - 1]);
            len--;
            push_heap(0, nums, len);
        }
        return *(nums.end() - i);
    }
};

class Solution {
public:

    void quickSort(vector<int>& nums, int start, int end)
    {
        int j = start+1;
        
        if (start >= end)
            return;
        for (int i = j; i <= end; i++) {
            if (nums[i] > nums[start])
                swap(nums[i], nums[j++]);
        }
        swap(nums[start], nums[j-1]);
        quickSort(nums, j, end);
        quickSort(nums, start, j-2);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        return nums[k-1];
    }
};

class Solution {
public:

    void quickSort(vector<int>& nums, int start, int end, int k)
    {
        int j = start+1;
        
        if (start >= end)
            return;
        for (int i = j; i <= end; i++) {
            if (nums[i] > nums[start])
                swap(nums[i], nums[j++]);
        }
        swap(nums[start], nums[j-1]);
        if (k == j-1)
            return;
        else if (k > j-1)
            quickSort(nums, j, end, k);
        else if (k < j-1)
            quickSort(nums, start, j-2, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1, k-1);
        return nums[k-1];
    }
};
