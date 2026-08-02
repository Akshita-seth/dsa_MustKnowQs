// Problem: Find Minimum in Rotated Sorted Array
//

// BFS: Linear search'
// TC: O(n), SC: O(1)

int findMin(vector<int>& arr) {
  
    int res = arr[0];

    // Traverse over arr[] to find minimum element
    for (int i = 1; i < arr.size(); i++) 
        res = min(res, arr[i]);

    return res;
}

// OS: Binary search
// TC: O(logN) SC: O(1)

int findMin(vector<int>& nums) {
        int n = nums.size();

        int low=0, high=n-1;

         // if current range sorted, low is minimum
         if(nums[low] < nums[high])
         return nums[low];

        while(low < high)
        {   
            int mid = low + (high - low)/2;

            // Minimum lies in the right half
            if(nums[mid] > nums[high])
            low = mid+1;

            // Minimum lies in the left half
            else
            high = mid;
        }

        return nums[low];
        
    }
