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


// Optimized using QuickSelect: Build on quicksort algo
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



