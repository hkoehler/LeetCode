// https://www.hackerrank.com/challenges/quicksort3

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> &nums, int low, int high) {
    int j = low;
    int pivot = nums[high];
    
    for (int i = low; i < high; i++)
        if (nums[i] <= pivot)
            swap(nums[i], nums[j++]);
    swap(nums[high], nums[j]);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
    return j;
}

void qsort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int j = partition(nums, low, high);
        qsort(nums, low, j - 1);
        qsort(nums, j + 1, high);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> nums;
    
    cin >> n;
    nums.resize(n);
    for (auto &num : nums)
        cin >> num;
    qsort(nums, 0, nums.size() - 1);
    return 0;
}

