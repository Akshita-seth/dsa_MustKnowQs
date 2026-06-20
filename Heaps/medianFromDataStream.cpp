// Problem: Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/
// https://www.geeksforgeeks.org/dsa/median-of-stream-of-integers-running-integers/


// BFS: Insertion Sort
// Maintain a sorted list of all numbers as they arrive. Each time you add a number, insert it into the correct position so the list stays sorted.
// TC: lower_bound -> O(logN), insert -> O(N) bcz shifting elemnts after the insert position is costly
// So overall each addNum is O(N), Median retrieval is O1)


class MedianFinder {
public:
    vector<int> nums;

    MedianFinder() {}

    void addNum(int num) {
        // Insert num into the sorted vector
        auto it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);  // O(n) because of shifting elements
    }

    double findMedian() {
        int n = nums.size();
        if (n % 2 == 1) {
            return nums[n / 2];  // middle element
        } else {
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;  // average of two middles
        }
    }
};



// Optimized Soln using two heaps for balancing halves
// TC: O(n * log n), All the operations within the loop (push, pop) take O(log n) time in the worst case for a heap of size n.
// SC: O(n)

class MedianFinder {
public:
priority_queue<int> left; //max heap for smaller half
priority_queue<int, vector<int>, greater<int>> right; //min heap for larger half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // step 1 push into max heap
        left.push(num);

        // step 2 balance by moving top of left to right
        right.push(left.top());
        left.pop();

        // step 3 ensure left ahs equal or one more element than right
        if(left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
          return (left.top()+right.top())/2.0;
        else 
          return left.top();
    }
};
