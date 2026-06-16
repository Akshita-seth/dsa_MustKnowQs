// Problem: Kth Largest Element In Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/


// With sorting:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0;
        while(i < nums.size()-k)
        {
            i++;
        }
        return nums[i];
    }
};
