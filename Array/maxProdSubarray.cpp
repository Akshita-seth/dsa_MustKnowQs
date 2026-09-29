// Problem: Maximum subarray product
// Link: https://leetcode.com/problems/maximum-product-subarray/

//BFS: TC:O(N^2) Nested i and j loop

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxP=nums[0];
      
        for(int i=0; i<n; i++)
        {
            int product = 1;
            for(int j=i; j<n; j++)
            {
                product *= nums[j];
                maxP = max(maxP, product);
            }
        }
        return maxP;
    }
};

// Optimized: using Prefix Sum TC: O(N) Two passes done simultaneously=> Forward and backward 
//False confusion caused: [-2,3,4,0,2,4] => catches 12, i.e., [3,4] during backward product using suffix.

// pre builds the product from left to right.
// suff builds the product from right to left.
// Reset at zero: If product becomes zero, reset to 1 so the next segment can start fresh.
// Max tracking: At each step, compare both prefix and suffix products with the current maximum.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1,suff=1;
        int maxP=INT_MIN;
        for(int i=0;i<n;i++){
           if(pre==0) pre=1;
           if(suff==0) suff=1;
           pre=pre*nums[i];
           suff=suff*nums[n-1-i];
           maxP=max(maxP,max(pre,suff));
            }
            return maxP;

    }
};


// Optimized using Kadane's as a State DP because there is an option to take or not take
//This is the “state DP” intuition: at each step, you decide whether to take or not take the previous state.
//We start with the first element because the maximum product subarray must include at least one element. maxEndingHere = best product ending at current index. 
//minEndingHere = worst product ending at current index (important because a negative × negative can flip to positive later).
//maxSoFar = global best seen so far.
// TC: O(N) One pass only

//Intuition:
// Swap step: handles negatives flipping signs.
// Compare with nums[i]: ensures we can “restart” the product at the current element.
// Track both min and max: because a large negative can become a large positive later.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxEndingHere, minEndingHere);

            maxEndingHere = max(nums[i], maxEndingHere * nums[i]);
            minEndingHere = min(nums[i], minEndingHere * nums[i]);

            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};


// Kadane’s DP (min/max tracking):
// Explicitly considers both nums[i] and products with previous min/max.
// Handles negatives and zeros systematically.
// Always correct, more intuitive to reason about.

// Prefix/Suffix trick:
// Simpler, just two rolling products.
// Works because the maximum product subarray must appear as some prefix or suffix of the array (after resets).
// Slightly less explanatory, but elegant and concise.

// Kadane’s DP is the canonical, more robust solution — it directly models the state transitions.
// Prefix/Suffix trick is a clever shortcut: it leverages two passes to capture the max product, even across zeros and negatives.
// For interviews or teaching, Kadane’s is preferred (clearer reasoning). For competitive coding, prefix/suffix is a neat alternative.
