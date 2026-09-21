// Problem: Climbing Stairs/ Count ways to reach Nth stair
// https://leetcode.com/problems/climbing-stairs/

// The recurrence relation for Climbing Stairs is:

// f(n) = f(n-1) + f(n-2)

// Base cases:
// f(0) = 1
// f(1) = 1

// recursive: 
// Understanding Base Cases:
// Think of n as "remaining steps to climb."

// Case n==0 → You’re already at the top.
// That means you’ve found one valid way to reach the goal (by completing the climb).
// So we return 1 to count this path.

// Case n==1 → Only one step left.
// You can take that single step, and that’s one valid way.
// So we return 1

// Issues: Exponential time complexity: Each call branches into two more calls, leading to repeated computations. Complexity is O(2^N)

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



