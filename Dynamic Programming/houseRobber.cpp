// Problem: House Robber I
// https://leetcode.com/problems/house-robber/


// Recursion
// What does maxRob(nums, n) mean?Here, n is not an index.
// It means: "Find the maximum money that can be robbed from the first n houses."
// maxRob(nums, 3) → solve for houses [0,1,2] and so on.

class Solution {
public:
    int maxRob(vector<int>& nums, int n)
    {
        if(n<=0)
        return 0;
        if(n==1)
        return nums[0]; // rob the remaining 1 house

        int pick = nums[n-1] + maxRob(nums, n-2);
        int notPick = maxRob(nums, n-1);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        return maxRob(nums, n);
    }
};
