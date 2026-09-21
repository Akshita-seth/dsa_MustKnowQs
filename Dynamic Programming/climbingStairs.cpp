// Problem: Climbing Stairs/ Count ways to reach Nth stair
// https://leetcode.com/problems/climbing-stairs/

// The recurrence relation for Climbing Stairs is:

// f(n) = f(n-1) + f(n-2)

// Base cases:
// f(0) = 1
// f(1) = 1

// Understanding Base Cases:
// Think of n as "remaining steps to climb."

// Case n==0 → You’re already at the top.
// That means you’ve found one valid way to reach the goal (by completing the climb).
// So we return 1 to count this path.

// Case n==1 → Only one step left.
// You can take that single step, and that’s one valid way.
// So we return 1

// RECURSIVE: 
// Issues: Exponential time complexity: Each call branches into two more calls, leading to repeated computations. 
// Complexity is O(2^N)

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
        return 1;
        if(n == 1)
        return 1;

        int oneSteps = climbStairs(n-1);
        int twoSteps = climbStairs(n-2);

        return oneSteps + twoSteps;
    }
};


// OPTIMIZATIONS: 

// MEMOIZATION: TC: O(N) SC: O(N) + O(N)
//initializing dp with -1 is imp so verify if it's calculated already or not

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
    int helper(int n, vector<int>& dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = helper(n-1, dp) + helper(n-2, dp);
        return dp[n];
    }
};

// TABULATION: TC: O(N) SC: O(N)
// No need of initializing with -1 for dp array, just initialise the base case values

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
        return 1;

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


// SPACE OPTIMIZED: TC: O(N) SC: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
        return 1;

        int prev1 = 1;
        int prev2 = 1;
        
        for(int i = 2; i<=n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
