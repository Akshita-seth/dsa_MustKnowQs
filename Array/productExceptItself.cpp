// Problem: Product of Array except Itself
// Link: https://leetcode.com/problems/product-of-array-except-self/description/
// Pattern: Prefix-Sum


//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approach: Nested loop, i and j

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int i=0; i<n; i++)
        {
            int prod=1;
            for(int j=0; j<n; j++)
            {
                if(j!=i)
                {
                    prod*=nums[j];
                }
            }
            result.push_back(prod);
        }
        return result;
    }
};

//Optimized: Two Pass Solution. 1st- Calculate leftProduct, 2nd- Find final result using rightProd variable
// TC: O(n+n) SC: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        result[0]=1;
        //first index as 1 only since nothing on the left of it so leftProduct 1
        //first we use result array to store the leftProduct/prefixProduct of the array.

        //For this we traverse from left to right in the array
        for(int l=1; l<n; l++)
        result[l] = result[l-1] * nums[l-1];
        
        //Now to take care of rightProduct/suffixProd we use a rightProd variable
        //from last index, rightProd as 1 only since nothing on the right of it
        int rightProd = 1; 
        
        //For this we traverse right to left in the array
        for(int r=n-1; r>=0; r--)
        {
            result[r] *= rightProd;
            rightProd *= nums[r];
        }
        return result;
    }
};

