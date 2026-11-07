// Problem: Frog Jump
// https://www.geeksforgeeks.org/problems/geek-jump/1



// Recursion: TC: O(2^n) SC: O(n)

class Solution {
  public:
    int recursion(vector<int>& height, int n)
    {
        if(n == 0)
        return 0;
        int right = INT_MAX;
        int left = recursion(height, n-1) + abs(height[n] - height[n-1]);
        if(n > 1)
        right = recursion(height, n-2) + abs(height[n] - height[n-2]);
        
        return min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        
        return recursion(height, n-1);
    }
};

// Memoization: TC: O(n) SC: O(2n)

class Solution {
  public:
    int recursion(vector<int>& height, int n, vector<int>& dp)
    {
        if(n == 0)
        return 0;
        if(dp[n] != -1)
        return dp[n];
        int right = INT_MAX;
        int left = recursion(height, n-1, dp) + abs(height[n] - height[n-1]);
        if(n > 1)
        right = recursion(height, n-2, dp) + abs(height[n] - height[n-2]);

        return dp[n] = min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n,-1);
        return recursion(height, n-1, dp);
    }
};



//Tabulation: TC: O(n) SC: O(n)

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        int fs = INT_MAX, ss = INT_MAX;
        
        for(int i=1; i<n; i++)
        {
            fs = dp[i-1] + abs(height[i] - height[i-1]);
            if(i>1)
            ss = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(fs, ss);
        }
        return dp[n-1];
    }
};


// Space Optimized: TC: O(n) SC: O(1)

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev = 0;
        int prev2 = 0;

        int fs = INT_MAX, ss = INT_MAX, curr;

        for(int i=1; i<n; i++)
        {
            fs = prev + abs(height[i] - height[i-1]);
            if(i>1)
            ss = prev2 + abs(height[i] - height[i-2]);

            curr = min(fs, ss);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
