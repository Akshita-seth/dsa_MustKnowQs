// Problem: Kth Largest Element In Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/


// With sorting:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k]; 
    }
};


// Optimized using heaps: complimentary of Kth Samllest
// S1-> create a min Heap with the first K elements
// S2- for the rest of the elements check => if element > heap.top() => heap.pop() => heap.push(element)
// This will result in the heap containing the first K largest elements, and the root of this heap will be the Kth largest element (this is why we took min-heap).

// TC: O(nlogk) => building a heap O(k), Processing the remaining (n-k) elements each push/pop is O(logk)
// SC: O(k)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<k; i++)
          minHeap.push(nums[i]);
        
        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};


// OS: TC: O(N) SC: O(1)
// O(N), where N is the size of the given array.
// In the average case (when the pivot is chosen randomly):
// Assuming the array gets divided into two equal parts, with every partitioning step, the search range is reduced by half. Thus, the time complexity is O(N + N/2 + N/4 + ... + 1) = O(N).

// In the worst-case scenario (when the element at the left or right index is chosen as the pivot):
// In such cases, the array is divided into two unequal halves, and the search range is reduced by one element with every partitioning step. Thus, the time complexity is O(N + N-1 + N-2 + ... + 1) = O(N2). 
// However, the probability of this worst-case scenario is negligible.



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
