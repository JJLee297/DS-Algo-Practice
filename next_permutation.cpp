#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
As we are essentially looking for the next largest arrangement of numbers in order, we first look for the pivot index.
Starting from the end, the pivot index is where the digit is less than the digit immediately before it. In the next permutation,
all the digits after the pivot will remain unchanged, and all the digits before and including the pivot will change. 
The pivot digit swaps with the next largest digit before it, and then the vector is sorted from (pivot, end].

If a pivot doesn't exist, that means we are at the last permuation, and we return the whole vector sorted. 

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int i = nums.size() - 1;
        for (i; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                pivot = i - 1;
                break;
            }
        }
        if (pivot == -1)
            return (sort(nums.begin(), nums.end()));
        i = nums.size() - 1;
        for (i; i >= pivot; i--) {
            if (nums[i] > nums[pivot]) {
                int tmp = nums[i];
                nums[i] = nums[pivot];
                nums[pivot] = tmp;
                break;
            }
        }
        return (partial_sort(nums.begin() + pivot + 1, nums.end(), nums.end()));
    }
};


int main() {
    Solution A;
    vector<int> nums{ 1, 3, 6, 4, 2, 5 };
    A.nextPermutation(nums);
    for (auto x : nums) {
        cout << x << " ";
    }
}
