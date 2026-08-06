// Problem: Longest Consecution Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/


// BFS:
// TC: O(n * log n), SC: O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())  // Edge case imp bcz otherwise empty vector gets output as 1 since longest = 1 initialised
        return 0;
        
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        int currCnt = 1, longest = 1;
        for(int i=1; i<n; i++)
        {
            //skipping duplicates
            if(nums[i] == nums[i-1])
            continue;

            else if(nums[i] - nums[i-1] == 1)
            {
                currCnt++;
                longest = max(longest, currCnt);
            }
            else
            currCnt = 1;
        }
        return longest;
    }
};


// OS: 
// Iterate over the set, not the vector. This removes duplicates automatically and ensures each number is considered once.[Also avoids TLE if 0<n<10^5]
// TC: O(n) Each number visited at most twice -> Once in the outer loop, once in the inner expansion. That’s why it’s truly O(N) average.
// SC: O(n)



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n =nums.size();

        // Hash all the array elements
        // unordered_set<int> st; 
        // for(int n:nums)
        // st.insert(n);

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        // check each possible sequence from the start then update optimal length
        for(int n:st)
        {
            if(st.find(n) != st.end() && st.find(n-1) == st.end()) // n can be the staring poinmt of sequence
            {
                // now check for further elements but can't modify the looping var n
                int curr = n, cnt = 0;
                while(st.find(curr) != st.end())
                {
                    cnt++;
                    curr++;
                }
                longest = max(longest, cnt);
            }

        }
        return longest;
    }
};
