// Problem: Three Sum
// Link: https://leetcode.com/problems/3sum/description/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero


//BFS: Three Nested Loops and set data structure to prevent duplicates
// TC: O(n^3) * O(log(no. of triplets)) sice insertion in set is logN as it is unique   
// SC: O(2*(no. of triplets)) for set and result

class Solution {
public:
    // Function to find triplets with sum zero
    vector<vector<int>> threeSum(vector<int>& arr, int n) {
        // Store unique triplets
        set<vector<int>> st;

        // First loop for first element
        for (int i = 0; i < n; i++) {
            // Second loop for second element
            for (int j = i + 1; j < n; j++) {
                // Third loop for third element
                for (int k = j + 1; k < n; k++) {
                    // If triplet sum is zero
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        // Store sorted triplet to avoid duplicates
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        // Convert set to vector
        vector<vector<int>> ans(st.begin(), st.end()); // Explained below
        return ans;
    }
};
//st.begin(), st.end() are iterators over the set.
// The vector constructor can take a range of iterators and copy all elements into the new vector.
// So this directly builds ans as a vector<vector<int>> from the contents of the set.


// Better: Hashset use to find third number
// TC: O(N2 * log(no. of unique triplets))
// SC : O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and
// a list to store the triplets and extra O(N) for storing the array elements in another set.

class Solution {
public:
    // Function to find triplets with sum zero
    vector<vector<int>> threeSum(vector<int>& arr, int n) {
        // Store unique triplets
        set<vector<int>> ans;

        // First loop for first element
        for (int i = 0; i < n; i++) {
            // Set to store elements seen in this iteration
            set<int> hashset;

            // Second loop for second element
            for (int j = i + 1; j < n; j++) {
                // Calculate third element needed
                int third = -(arr[i] + arr[j]);

                // If third already in set, we found a triplet
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                // Add current element to set
                hashset.insert(arr[j]);
            }
        }
        // Convert set to vector
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};


// Optimized: 
// TC: O(NlogN)+O(N^2) sorting + TwoPointer * i loop, SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; //avoiding duplicates (substitutes using set data structure)
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while(j<k && nums[j]==nums[j-1]) j++;  //avoiding duplicates (substitutes using set data structure)
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
