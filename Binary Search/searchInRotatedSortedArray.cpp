// Problem: Search in Rotated Soted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// BFS: Linear search
// TC: O(n), SC: O(1)

// BS: Two binary search 
// TC: O(logN), SC:O(1)

// Why low + (high - low)/2 works
// (high - low) is always within the array size (at most n).
// Instead of measuring the whole rope length (low + high), you measure the difference (high - low)
// then add half of that to the starting point (low).
// So low + (high - low)/2 stays safe and avoids overflow.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Find pivot (index of smallest element)
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                // Pivot is in the right half
                low = mid + 1;
            } else {
                // Pivot is in the left half (including mid)
                high = mid;
            }
        }
        int pivot = low;

        // Step 2: Normal binary search with pivot adjustment
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Adjusted mid to account for rotation
            int realMid = (mid + pivot) % n;

            if (nums[realMid] == target) return realMid;
            if (nums[realMid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};



// OS: SIngle Binary search
// Identify the sorted half and checkif target lies in that half or the other

int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high)
        {
            int mid = (low+high) /2;

            if(nums[mid] == target)
            return mid;

            // Left half sorted
            if(nums[low] <= nums[mid])
            {
                // Check if target lies on the left half
                if(nums[low] <= target && target <= nums[mid])
                high = mid-1; // eliminates right half
                else
                low = mid + 1; //eliminates left half
            }

            // Right half sorted
            else
            {
                //Check if target lies on right side
                if(nums[mid] <= target && target <= nums[high])
                low = mid+1; //left half eliminated
                else
                high = mid - 1;  // right half eliminated
            }
        }
        return -1;
    }
