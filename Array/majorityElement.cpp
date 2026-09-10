// Problem: Majority Element
// https://leetcode.com/problems/majority-element/

// BFS: Check each element’s frequency by scanning the array
// TC: O(n^2) SC: O(1)

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) count++;
        }
        if (count > n/2) return nums[i];
    }
    return -1;
}

// BS: Using hashmap, one pass to build frequency map, one pass to check majority
// TC: O(n) SC: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq; //{val->freq}
        for(auto x:nums)
        freq[x]++;

        for(auto p:freq)
        {
            if(p.second > n/2)
            return p.first;
        }
        return 0;
    }
};


// OS: Boyer–Moore Majority Vote Algorithm
// Core Idea
// If an element appears more than n/2 times, it will survive any cancellation process against other elements.
// Think of it like a voting system: the majority element always wins because it has more than half the votes.
// Intuition in one line: “Pair off different elements until one survives — the survivor must be the majority
// The algorithm works because the majority element’s frequency is so high that even after canceling with all other elements, it still survives as the candidate.
// TC: O(n), SC: O(1)
// Boyer–Moore Majority Vote Algorithm Intuition
// You keep a candidate and a count.
// When you see the same number as the candidate, you increase the count (like gaining support).
// When you see a different number, you decrease the count (like losing support).
// If the count drops to zero, you pick the new number as the candidate (like switching allegiance).
// Because the majority element has more than half the votes, it can’t be completely canceled out — it will always re-emerge as the candidate.


int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

