// Problem: Max sum subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Pattern for optimization: KADANE'S Algo

//BFS: TC: O(N^2) 
// Nested i and j. Generate all subarrays.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxS = nums[0];
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum+=nums[j];
                maxS= max(maxS, sum);
            }
        }
        return maxS;
    }
};

// OS: TC: O(N), SC:O(1)
// If extending makes the sum worse, you “slide” the window start forward to i.
// So Kadane’s is a greedy sliding window that shrinks instantly when the prefix sum goes negative.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];   // current window sum
    int maxS = nums[0];   // best seen so far

    for(int i=1; i<nums.size(); i++) {
        // decide: extend or restart
        curr = max(nums[i], curr + nums[i]);
        maxS = max(maxS, curr);
    }
    return maxS;
    }
};
