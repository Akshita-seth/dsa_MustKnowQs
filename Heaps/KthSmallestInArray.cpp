// Problem: Kth Smallest element in array
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

//BFS: Sorting
// TC: O(nlogn)
// SC: O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k]; 
    }
};


// Better Soln: using Heaps
// S1-> create a max Heap with the first K elements
// S2- for the rest of the elements check => if element < heap.top() => heap.pop() => heap.push(element)
// This will result in the heap containing the first K small elements, and the root of this heap will be the Kth Smallest element (this is why we took max-heap).

// TC: O(nlogk) => building a heap O(k), Processing the remaining (n-k) elements each push/pop is O(logk)
// SC: O(k)


class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxHeap;
        
        for(int i=0; i<k; i++)
          maxHeap.push(arr[i]);
         
         for(int i=k; i<arr.size(); i++)
         {
             if(arr[i] < maxHeap.top())
             {
                 maxHeap.pop();
                 maxHeap.push(arr[i]);
             }
         }
         return maxHeap.top();
    }
};


// Optimized using QuickSelect: (Build on quicksort algo) Can find the top kth element from an unsorted data [top can mean smallest or largest]]
// Pick a pivot element (commonly the last element, or a random one for better average performance).
// Partition the array so that:
// Elements smaller than pivot go to the left.
// Elements larger than pivot go to the right.
// After partitioning, the pivot ends up at its correct sorted position pos.
// Compare pos with k-1 (for Kth smallest):
// -> If pos == k-1, pivot is the answer.
// -> If pos > k-1, recurse into the left side.
// -> If pos < k-1, recurse into the right side.

// TC: (N) avg, O(N^2) worst(poor pivots), but randomized pivot makes worst case rare.
// SC: O(1)



class Solution {
private:
    // Function to get a random index 
    int randomIndex(int &left, int &right) {
        // length of the array 
        int len = right - left + 1;
        
        // Return a random index from the array 
        return (rand() % len) + left;
    }
    
    // Function to perform the partition and return the updated index of pivot
    int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex]; // Get the pivot element
        
        // Swap the pivot with the left element
        swap(nums[left], nums[pivotIndex]);
        
        int ind = left + 1; // Index to mark the start of right portion
        
        // Traverse on the array 
        for(int i = left + 1; i <= right; i++) {
            
            // If the current element is greater than the pivot
            if(nums[i] > pivot) {
                // Place the current element in the left portion
                swap(nums[ind], nums[i]);
                
                // Move the right portion index
                ind++;
            }
        }
        
        swap(nums[left], nums[ind-1]); // Place the pivot at the correct index
        
        return ind-1; // Return the index of pivot now
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // Return -1, if the Kth largest element does not exist
        if(k > nums.size()) return -1;
        
        // Pointers to mark the part of working array 
        int left = 0, right = nums.size() - 1;
        
        // Until the Kth largest element is found
        while(true) {
            // Get the pivot index
            int pivotIndex = randomIndex(left, right);
            
            // Update the pivotIndex
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);
            
            // If Kth largest element is found, return
            if(pivotIndex == k-1) return nums[pivotIndex];
            
            // Else adjust the end pointers in array 
            else if(pivotIndex > k-1) right = pivotIndex - 1;
            else left = pivotIndex + 1;
        }
        
        return -1;
    }
};
