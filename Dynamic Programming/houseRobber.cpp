// Problem: House Robber I
// https://leetcode.com/problems/house-robber/


// Recursion: TC: O(2^n), SC: O(n)
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


// Memoization

class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == 1) return nums[0];
        if (idx == 0) return 0;

        if (dp[idx] != -1) return dp[idx];

        int pick = nums[idx-1] + solve(idx - 2, nums, dp);
        int notPick = solve(idx - 1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);

        return solve(n, nums, dp);
    }
};



//IF n was treated as index 




// Tabulation: TC: O(n) SC: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2; i<=n; i++)
        {
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
};
