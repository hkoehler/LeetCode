// https://leetcode.com/problems/range-sum-query-mutable/

#include <iostream>
#include <vector>
#include <cassert>

#define LOG 1

using namespace std;

struct Segment
{
    Segment(size_t b, size_t e, int v) :
        begin(b), end(e), val(v), left(nullptr), right(nullptr) {}
    size_t begin, end;
    int val;
    Segment *left, *right;
};

class NumArray {
    Segment *tree;
    vector<int> nums;
    
    Segment *buildTree(vector<int> &nums, int begin, int end) {
        int val = 0;
        this->nums = nums;
        if (begin > end)
            return nullptr;
        else if (begin == end)
            return new Segment(begin, end, nums[begin]);
        for (int i = begin; i <= end; i++)
            val += nums[i];
        auto segment = new Segment(begin, end, val);
        int middle = begin + (end - begin) / 2;
        segment->left = buildTree(nums, begin, middle);
        segment->right = buildTree(nums, middle+1, end);
        return segment;
    }
    
    int lookup(Segment *tree, size_t i) {
        Segment *seg = tree;
        int sum = 0;
        
        while (seg->end != i) {
#ifdef LOG
            cout << "lookup (" << seg->begin << "," << seg->end << ")" << endl;
#endif
            if (seg->left && seg->left->end < i) {
                sum += seg->left->val;
                seg = seg->right;
            } else if (seg->left && seg->left->end >= i) {
                seg = seg->left;
            } else
                assert(0);
        }
        return seg->val + sum;
    }
    
    void updateTree(Segment *tree, size_t i, int diff) {
        Segment *seg = tree;

        for (;;) {
#ifdef LOG
            cout << "update (" << seg->begin << "," << seg->end << ")" << endl;
#endif
            seg->val += diff;
            if (seg->left && seg->left->end >= i) {
                seg = seg->left;
            } else if (seg->right) {
                assert(seg->right->begin <= i);
                seg = seg->right;
            } else
                break;
        }
    }
public:
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
        tree = buildTree(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        if (nums.empty())
            return;
        int diff = val - nums[i];
#ifdef LOG
        cout << "update " << i << " from " << nums[i] << " to " << val << endl;
#endif
        updateTree(tree, i, diff);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        if (nums.empty())
            return 0;
        int n1 = 0;
        if (i > 0)
            n1 = lookup(tree, i-1);
#ifdef LOG
        cout << "look up " << i << " " << n1 << endl;
#endif
        int n2 = lookup(tree, j);
#ifdef LOG
        cout << "look up " << j << " " << n2 << endl;
#endif
        return n2 - n1;
    }
};

int main(int argc, char *argv[])
{
    size_t size;
    vector<int> nums;
    
    // read array
    cin >> size;
    nums.resize(size);
    for (auto &n : nums)
        cin >> n;
    
    NumArray numArray(nums);
    // read either "sum i j", "update i n" or done
    for (;;) {
        string op;
        
        cin >> op;
        if (op == "sum") {
            int i,j;
            cin >> i >> j;
            cout << numArray.sumRange(i, j) << endl;
        } else if (op == "update") {
            int i, n;
            cin >> i >> n;
            numArray.update(i, n);
        } else
            break;
    }
    return 0;
}

