// Problem: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/description/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s

// BFS: Count number of 0s, 1s and 2s then overwrite in the array - Two pass solution
// TC: O(n)  SC:O(1)

//Optimized: DUTCH NATIONAL FLAG ALGORITHM - One pass solution
// TC: O(n) SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++; mid++;
            }
            else if(nums[mid]==1)
            mid++;
            else
            {
              swap(nums[mid],nums[high]);
              high--;
            }
        }
        
    }
};
