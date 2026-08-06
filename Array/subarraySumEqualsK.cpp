// Problem: No. of Subarrays with Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Pattern: Prefix-Sum
//https://takeuforward.org/arrays/count-subarray-sum-equals-k
//https://www.youtube.com/watch?v=xvNwoz-ufXA&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=34

//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approch: Nested loop i and j to generate all subarrays, then check sum and count

int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum == k)
                cnt++;
            }
        }
        return cnt;
    }


//Optimized: TC: O(N*logN) [ordered map], O(N*1) [Unordered map best and avg case], O(N*N) [Unorderd map worst case due to collisions]
// SC: O(N) map
//Approach: V.Imp 1.storing key as prefix sum and value as freq 
// 2. prefixSum[0] =1; first entry in map


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        mpp[0]=1;
        int preSum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            preSum +=nums[i];
            int remove=preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};

