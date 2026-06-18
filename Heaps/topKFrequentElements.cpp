// Problem: Top K Frequent Elements in array
// https://leetcode.com/problems/top-k-frequent-elements/



// BFS: (Expected) Custom Heap soln
// TC: O(n+mlogk) worst case O(nlogk) all elements unique
// O(N) -> for freq map building traversed once, Iterate over freq entries O(M) or at most O(N) and each push/pop is O(log K) thus O(MlogK), extract K elements from heap O(logK)
// SC: O(N) freq map + O(K) heap


struct customComparator {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first; 
        // min-heap: smaller frequency has higher priority
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++; // build frequency map
        }

        // min-heap storing (frequency, element)
        priority_queue<pair<int,int>, vector<pair<int,int>>, customComparator> minHeap;

        for (auto &p : freq) {
            minHeap.push({p.second, p.first}); // (frequency, element)
            if (minHeap.size() > k) minHeap.pop(); // keep heap size = k
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second); // extract element
            minHeap.pop();
        }
        return ans;
    }
};
