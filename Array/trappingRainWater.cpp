// Problem: Trapping Rainwater
// Link: https://leetcode.com/problems/trapping-rain-water/description/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/trapping-rainwater

// What if width = n instead of 1?
// If each block has width = n instead of 1, then every unit of trapped water spans n units horizontally.
// That means the total trapped water volume is simply:

// Total Water (with width n)=TotalWater (width=1)×𝑛

// BFS: Taking current element i, callc maxLeft and maxRight each time with j loop, then calc total water: total += min(maxLeft, maxRight) - height[i];
// TC: O(n^2)  SC:O(1)

int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        for(int i=0; i<n; i++)
        {
            int maxLeft =0, maxRight=0;
            for(int j=0; j<=i; j++)
            {
                maxLeft = max(maxLeft, height[j]);
            }
            for(int j=i; j<n; j++)
            {
                if(height[j] > maxRight)
                maxRight = height[j];
            }
            total += min(maxLeft, maxRight) - height[i];
        }
        return total;
    }

//Optimized: 
// TC: O(n) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int left = 0, right = n-1;
        int maxLeft=0, maxRight=0;
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= maxLeft)
                maxLeft = height[left];
                else
                totalWater+= maxLeft - height[left];

                left++;
            }
            else
            {
                if(height[right] >= maxRight)
                maxRight = height[right];
                else
                totalWater+= maxRight - height[right];

                right--;
            }
        }
        return totalWater;
    }
};

// Also correct
int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int left = 0, right = n-1;
        int maxLeft = height[0], maxRight = height[n-1];
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] > maxLeft)
                maxLeft = height[left];
                else
                    total += maxLeft - height[left];
                    left++;
                             
            }
            else
            {
                if(height[right] > maxRight)
                maxRight = height[right];
                else
                    total += maxRight - height[right];
                    right--;
                     
            }
        }
        return total;
    }


// Difference:  
// 👉 If left++ / right-- are placed inside the water‑calculation else, the pointer moves only when water is added. 
//If they’re placed outside, the pointer moves every iteration — but it’s still correct because when boundaries are updated, water at that index is zero, so skipping forward is safe.
// That’s the invariant: each index is processed once, either by updating boundary or adding water, so unconditional pointer movement still yields the same total.
