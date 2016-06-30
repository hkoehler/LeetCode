class Solution {
public:
    void swap(int &a, int &b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }

    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        
        // find adjacent number which violate ordering
        for (int i = nums.size() - 2; i >= 0; i--)
            if (nums[i] < nums[i+1]) {
                cout << "i=" << i << endl;
                // swap nums[i] with smallest possible number
                int j;
                
                for (j = nums.size() - 1; j > i; j--)
                    if (nums[j] > nums[i])
                        break;
                cout << "j=" << j << endl;
                swap(nums[i], nums[j]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        // numbers are reverse sorted
        sort(nums.begin(), nums.end());
    }
};
