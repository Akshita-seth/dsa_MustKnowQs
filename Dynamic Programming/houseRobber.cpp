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

// If n treated as index


class Solution {
public:
    int maxRob(vector<int>& nums, int n)
    {
        if(n < 0)
        return 0;
        if(n == 0)
        return nums[0];

        int pick = nums[n] + maxRob(nums,n-2);
        int notPick = maxRob(nums,n-1);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return maxRob(nums, n-1);
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

class Solution {
public:
    int maxRob(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n < 0)
        return 0;
        if(n == 0)
        return nums[0];

        if(dp[n] != -1)
        return dp[n];

        int pick = nums[n] + maxRob(nums,n-2, dp);
        int notPick = maxRob(nums,n-1, dp);

        return dp[n] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return maxRob(nums, n-1, dp);
    }
};


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

// if n was treated as index

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        int pick, notPick;

        for(int i=1; i<n; i++)
        {
            pick = nums[i];
            if(i > 1) pick += dp[i-2];
            notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
};


// Space optimization: TC: O(n) SC: O(1)
// here n taken as index

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev1 = nums[0];
        int prev2 = 0;
        int pick, notPick, curr;

        for(int i=1; i<n; i++)
        {
            pick = nums[i];
            if(i > 1) pick += prev2;
            notPick = prev1;

            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};


// problem: House Robber II
// https://leetcode.com/problems/house-robber-ii/


class Solution {
public:
    int maxRob(vector<int>& arr)
    {
        int prev2 = 0;
        int prev1 = arr[0];
        int curr, pick, notPick;

        for(int i=1; i<arr.size(); i++)
        {
            pick = arr[i];
            if(i>1)
            pick += prev2;
            notPick = prev1;

            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return nums[0];

        vector<int> temp1, temp2;

        for(int i=0; i<n; i++)
        {
            if(i != 0)
            temp1.push_back(nums[i]);
            if(i != n-1)
            temp2.push_back(nums[i]);
        }

        return max(maxRob(temp1), maxRob(temp2));
    }
};
