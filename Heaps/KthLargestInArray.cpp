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
