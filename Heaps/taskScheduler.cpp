// Problem: task Scheduler
// https://leetcode.com/problems/task-scheduler/

// BFS: (Simulation with timeline array) Actually build the schedule timeline, placing tasks and idle slots explicitly.
// TC: O(N* time) → very inefficient.

// Better soln: Use a max‑heap to always pick the most frequent task. Simulate cycles of length n+1
// TC: O(NlogK) (N=number of tasks, k=number of distinct tasks) building freq map O(N), heap operations Each task can be pushed/popped at most once per cycle → (NlogK)
// SC: O(K) for heap and freq map

class Solution {

    struct customComparator {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
            // max-heap: higher frequency has higher priority
        } // comparator true => consider a before b
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        // build frequency map
        map<char, int> freq;
        for (char ch : tasks)
            freq[ch]++;

        // push into maxHeap
        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       customComparator>
            maxHeap; // for frequency
        for (auto it : freq) {
            maxHeap.push({it.first, it.second});
        }
        int intervals = 0;

        // process until heap is empty
        while (!maxHeap.empty()) {
            vector<pair<char, int>> temp;
            int cycle = n + 1;
            // fill one cycle
            for (int i = 0; i < cycle && !maxHeap.empty(); i++) {
                auto curr = maxHeap.top();
                maxHeap.pop();
                curr.second--; // scheduled once
                temp.push_back(curr);
                intervals++; // count this slot
            }
            // push back asks into the heap which still have remaining freq
            for (auto& p : temp) {
                if (p.second > 0)
                    maxHeap.push(p);
            }
            // if heap is not empty, we must account for idle slots to complete
            // this cycle
            if (!maxHeap.empty())
                intervals += (cycle - temp.size());
        }
        return intervals;
    }
};


// Optimized: Math formula
