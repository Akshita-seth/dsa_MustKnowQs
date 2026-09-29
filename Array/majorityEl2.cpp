// Problem: Majority Element 2
// https://leetcode.com/problems/majority-element-ii/


// Keep in mind:
// As you scan through candidates and push qualifying ones into answer, once you’ve already found 2, you can safely stop.
// No third element can possibly qualify, so continuing the loop is wasted work.
// If one element appears more than n/3 times, it takes up a big chunk of the array.
// If you try to fit 3 different elements each taking more than n/3, the total would go over n (the array size).
// That’s impossible, so at most 2 elements can qualify.

// In Majority Element 1, there's only 1 num that can have freq>n/2 bcz only 1 is possible.
// In Majority Element 2, only 2 at amx is pssbl for having freq>n/3.



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

            if (ans.size() == 2)
                break;
        }
        return ans;
    }
};


//  Better:
// TC: O(N) SC: O(N)


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans;

        for(int num: nums)
        freq[num]++;
        
        for(auto p:freq)
        {
            if(p.second > n/3)
               ans.push_back(p.first);
            if (ans.size() == 2)
                break;
        }
        return ans;
    }
};
