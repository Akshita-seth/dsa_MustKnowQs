// Problem: Next Permutation
// https://leetcode.com/problems/next-permutation/
// https://www.youtube.com/watch?v=JDOXKqF60RQ



// BFS:
// The idea is that we would first generate all possible permutations of a given array and sort them. Once sorted, we locate the current permutation within this list. 
// The next permutation is simply the next arrangement in the sorted order. 
// If the current arrangement is the last in the list then display the first permutation (smallest permutation).

// OS: 
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
