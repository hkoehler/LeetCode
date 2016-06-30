// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode *construct(vector<int> &nums, int begin, int end) {
        int middle = begin + (end - begin + 1) / 2;

        if (begin < 0 || end >= nums.size())
            return nullptr;
        if (begin > end)
            return nullptr;
        auto node = new TreeNode(nums[middle]);
        if (begin != end) {
            node->left = construct(nums, begin, middle - 1);
            node->right = construct(nums, middle + 1, end);
        }
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};
