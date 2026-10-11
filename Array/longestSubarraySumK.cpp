// Problem: Longest subarray with sum K OR Maximum size subarray sum equals K
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/


// BFS: nested loop
// TC: O(N^2)

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;

        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum == k)
                  maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    }
};

// OS: For every index i, if a previous prefix sum equals currentPrefix - k, then the subarray between those two indices has sum k; storing the earliest occurrence gives the longest such subarray.
// Also don't forget to pre-insert mpp[0] = -1 bcz if prefix == k
// TC: O(N) SC: O(N)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> mpp;
        int len = 0;
        long long prefix=0;

        mpp[0] = -1;  // handles subarrays starting at index 0

        for(int i=0; i<n; i++)
        {
            prefix += nums[i];

            if(mpp.find(prefix-k) != mpp.end())
            len = max(len, i-mpp[prefix - k]);

            // store first occurrence only
            if(mpp.find(prefix) == mpp.end())
            mpp[prefix] = i;
        }
        return len;
    }
};
