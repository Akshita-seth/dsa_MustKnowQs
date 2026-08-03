// Problem: Single Number
// https://leetcode.com/problems/single-number/description/

//TC: O(N)  SC: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num: nums)
        {
            ans ^= num;  // xor accumulates
        }
        return ans;
    }
};
