// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int findPivot(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            int m = i + (j - i) / 2;
            
            if (nums[i] < nums[j])
                break;
            if (nums[i] > nums[m])
                j = m;
            else if (nums[m] > nums[j])
                i = m + 1;  // nums[m] can't be min
        }
        return i;
    }

    int find(vector<int>& nums, int target, int pivot) {
        int i = 0;
        int n = nums.size();
        int j = n - 1;
        
        while (i < j) {
            int m = i + (j - i) / 2;
            int mv = nums[(m + pivot) % n];
            
            if (mv > target)
                j = m - 1;
            else if (mv < target)
                i = m + 1;
            else {
                i = m;
                break;
            }
        }
        return (i + pivot) % n;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int pivot = findPivot(nums);
        //cout << "pivot=" << pivot << endl;
        int index = find(nums, target, pivot);
        if (nums[index] == target)
            return index;
        else
            return -1;
    }
};
