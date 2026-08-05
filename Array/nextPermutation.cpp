// Problem: Next Permutation
// https://leetcode.com/problems/next-permutation/
// https://www.youtube.com/watch?v=JDOXKqF60RQ



// BFS:
// The idea is that we would first generate all possible permutations of a given array and sort them. Once sorted, we locate the current permutation within this list. 
// The next permutation is simply the next arrangement in the sorted order. 
// If the current arrangement is the last in the list then display the first permutation (smallest permutation).

// Yes — since nums is passed by reference into the recursive permute() function, the swaps inside recursion do temporarily change the original vector.
// But here’s the key:
// We backtrack after each recursive call by swapping back (swap(nums[l], nums[i]) again).
// This ensures that when recursion unwinds, the vector returns to its previous state.
// Without backtracking, the original nums would indeed end up scrambled after recursion.

// So the temporary mutation is necessary to explore each branch, but the backtracking step restores the original state.
// 👉 If you want to avoid touching the original array at all, you could pass nums by value (copy) into permute(). 
// That way, each recursive call works on its own copy. But that’s less efficient




#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int l, int r, vector<vector<int>>& all) {
    if (l == r) {
        all.push_back(nums);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(nums[l], nums[i]);
        permute(nums, l + 1, r, all);
        swap(nums[l], nums[i]); // backtrack
    }
}

vector<int> nextPermutationBrute(vector<int>& nums) {
    vector<vector<int>> all;
    permute(nums, 0, nums.size() - 1, all);

    sort(all.begin(), all.end()); // sort all permutations

    // find current permutation
    auto it = find(all.begin(), all.end(), nums);

    if (it == all.end()) return nums; // safety check
    if (next(it) == all.end()) {
        return all.front(); // wrap around to smallest
    } else {
        return *next(it);   // next permutation in sorted order
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> res = nextPermutationBrute(nums);

    for (int x : res) cout << x << " ";
    return 0;
}



// OS: 1

// Function to find the next permutation
void nextPermutation(vector<int>& arr) {

    // Rearranges elements into the next lexicographical order
    // If already last permutation, rearranges to the smallest
    next_permutation(arr.begin(), arr.end());
}

// OS 2: 
// 1st Observation is: Longer prefix match find so where's the break point? move from right to left -> if (arr[i] < arr[i+1])
// 2nd: To replace arr[i], move from right and find num just greater than arr[i], i.e. next greater
// 3rd: Now place the remaining places with the remaining numbers in ascending sorted order, so that it's nearest to the given array
// TC: O(n) SC: O(1)

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1)
           {
            reverse(nums.begin(), nums.end());
            return;
           } 

        // Step 2: Find the element just larger than nums[i] to the right
        for (int i = n - 1; i >= idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // Step 3: Reverse the suffix
        reverse(nums.begin() + idx + 1, nums.end());
       
    }
