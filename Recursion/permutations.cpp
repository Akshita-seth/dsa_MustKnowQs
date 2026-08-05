// Problem: Generate all permutations
// https://leetcode.com/problems/permutations/


// TC: O(n!.n), SC:(n!.n) [output storage], + O(n) for recusrion depth
// Backtracking with swap + recursion 

class Solution {
public:
    void permutations(vector<int>& nums, int left, int right,
                      vector<vector<int>>& all) {
        if (left == right) {
            all.push_back(nums);
            return;
        }
        for (int i = left; i <= right; i++) {
            swap(nums[left], nums[i]);
            permutations(nums, left + 1, right, all);
            swap(nums[left], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        int n = nums.size();
        permutations(nums, 0, n - 1, all);
        return all;
    }
};



// Using STL built-in fn
// TC: O(n!.n), SC:(n!.n) [output storage]
// It’s designed to generate permutations in strict lexicographic order. But first u have to sort the given vector
// next_permutation → always gives the next arrangement in lexicographic order.
// To cover all permutations, start from the sorted array (smallest order).
// Without sorting, you only get permutations after your starting point, not the full set.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());   // start with smallest lexicographic order
        do {
            result.push_back(nums);       // store current permutation
        } while (next_permutation(nums.begin(), nums.end())); 
        return result;
    }
};
