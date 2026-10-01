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


// OPTIMAL:
// Initialize two candidate slots with counters set to zero because the result can contain at most two qualifying values.
// The extended Boyer–Moore Voting Algorithm therefore keeps only two candidates and two counters.
// Every answer must appear at least ⌊n/3⌋ + 1 times. If three distinct values each appeared that often, their combined frequency would be greater than n, which is impossible. Therefore, only two candidate slots are needed.
// Vote cancellation identifies possible answers, not guaranteed answers. For example, an array may contain several balanced values and no value may exceed ⌊n/3⌋. The final candidates must be counted again before they are returned.

// TC: O(N) SC: O(1)


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Step 1: Find two possible candidates
        int candidate1 = nums[0];
        int candidate2 = nums[0];
        int count1 = 0;
        int count2 = 0;

        for(int n: nums)
        {
            if(n == candidate1)
            count1++;
            else if(n == candidate2)
            count2++;
            else if(count1 == 0)
            {
                candidate1 = n;
                count1 = 1;
            }
            else if(count2 == 0)
            {
                candidate2 = n;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        //// Step 2: Verify the candidates
         count1 = 0, count2 = 0;
        for(int n: nums)
        {
            if(n == candidate1) count1++;
            else if(n == candidate2) count2++;
        }

        vector<int> ans;
        int len = nums.size();
        if(count1 > len/3) ans.push_back(candidate1);
        if(count2 > len/3) ans.push_back(candidate2);

        return ans;
    }
};



// For n/k At most k - 1 values can cross that threshold. A generalized voting algorithm maintains k - 1 candidate slots, cancels votes when a new value matches no active slot, and verifies every remaining candidate in a final traversal. 
// Its time complexity is O(nk) with a straightforward slot scan and its auxiliary space is O(k).
