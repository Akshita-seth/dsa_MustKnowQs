// Problem: Container with Most Water
// Link: https://leetcode.com/problems/container-with-most-water/description/
// Pattern: Two-pointer

// BFS: Nested loop, try all possible pairs
// TC: O(n^2)  SC:O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int water = width * min(height[i], height[j]);
                maxWater = max(maxWater, water);
            }
        }
        
        return maxWater;
    }
};

//Optimized: calc are by two pointers and move the pointer pointing the shorter line
// TC: O(n) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int width, maxWater=0;
        int left=0, right=n-1;
        while(left < right)
        {
           width = right - left;
           maxWater = max(maxWater, width* min(height[left], height[right]));
           if(height[left] < height[right])
           left++;
           else
           right--;
        }
        return maxWater;
    }
};
