// Problem: Search in Rotated Soted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// BFS: Linear search
// TC: O(n), SC: O(1)

// OS: Binary search
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
