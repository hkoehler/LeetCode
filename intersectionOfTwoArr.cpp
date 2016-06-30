// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1, s2;

        for (auto n : nums1)
            s1.insert(n);
        for (auto n : nums2)
            if (s1.find(n) != s1.end())
                s2.insert(n);
        for (auto n : s2)
            res.push_back(n);
        return res;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        // sort both input vectors
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            // skip duplicates
            if (!res.empty()) {
                if (res.back() == nums1[i]) {
                    i++;
                    continue;
                }
                if (res.back() == nums2[j]) {
                    j++;
                    continue;
                }
            }
            // found common element
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                j++; i++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

class Solution {
public:
    void qsort(vector<int> &nums, int begin, int end) {
        if (end <= begin)
            return;
        int p = nums[begin];
        int j = begin + 1;
        for (int i = j; i <= end; i++)
            if (nums[i] < p)
                swap(nums[i], nums[j++]);
        swap(nums[begin], nums[j-1]);
        qsort(nums, begin, j-2);
        qsort(nums, j, end);
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        // sort both input vectors
        qsort(nums1, 0, nums1.size()-1);
        qsort(nums2, 0, nums2.size()-1);
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            // skip duplicates
            if (!res.empty()) {
                if (res.back() == nums1[i]) {
                    i++;
                    continue;
                }
                if (res.back() == nums2[j]) {
                    j++;
                    continue;
                }
            }
            // found common element
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                j++; i++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

class Solution {
public:
    bool bsearch(vector<int> &nums, int n) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (nums[m] == n)
                return true;
            else if (nums[m] < n)
                i = m+1;
            else
                j = m-1;
        }
        return false;
    }

    void qsort(vector<int> &nums, int begin, int end) {
        if (end <= begin)
            return;
        int p = nums[begin];
        int j = begin + 1;
        for (int i = j; i <= end; i++)
            if (nums[i] < p)
                swap(nums[i], nums[j++]);
        swap(nums[begin], nums[j-1]);
        qsort(nums, begin, j-2);
        qsort(nums, j, end);
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res, res2;
        int prev;

        // sort first vector
        qsort(nums1, 0, nums1.size()-1);
        // bsearch in second vector
        for (int i = 0; i < nums2.size(); i++) {
            if (bsearch(nums1, nums2[i]))
                res.push_back(nums2[i]);
        }
        // dedup result
        qsort(res, 0, res.size()-1);
        prev = res[0];
        res2.push_back(prev);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] != prev) {
                prev = res[i];
                res2.push_back(prev);
            }
        }
        return res2;
    }
};
