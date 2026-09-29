// Problem: Majority Element 2
// https://leetcode.com/problems/majority-element-ii/


//BFS:
// TC: O(N^2), SC: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            auto it = find(ans.begin(), ans.end(), nums[i]);  // to avoid duplicates
            if(it != ans.end())
            continue;

            int count = 0;

            for(int j=0; j<n; j++)
            {
                if(nums[j] == nums[i])
                count++;
            }
            if(count > n/3)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
