// Problem: Merge Intervals
// https://leetcode.com/problems/merge-intervals/

// BFS: 
// For each interval, check against every other interval to see if they overlap.
// If yes, merge and keep repeating until no merge possible
// TC: O(n^2) because for each interval you may scan all others repeatedly. SC: O(n) for visited.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;

            int start = intervals[i][0];
            int end   = intervals[i][1];
            visited[i] = true;

            // BFS-like expansion: keep merging with overlapping intervals
            for(int j = i+1; j < n; j++) {
                if(!visited[j]) {
                    if(intervals[j][0] <= end && intervals[j][1] >= start) {
                        // overlap → expand boundaries
                        start = min(start, intervals[j][0]);
                        end   = max(end, intervals[j][1]);
                        visited[j] = true;
                        j = i; // restart scan to catch new overlaps
                    }
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};


// OS: Sort + SIngle pass merge
// TC: O(nlogn) due to sorting, plus O(n) for the merge pass.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // sort just on the basis of start time using lambda fn
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0]; // since ascending, if descending a[0] > b[0]
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]); //Initialising with first interval(starting interval, since sorted)

        for(int i=1; i<n; i++)
        {
            vector<int>& last = ans.back(); // change is done in original ans vector hence take refrence in 'last' vector
            vector<int> curr = intervals[i];
            if(curr[0] <= last[1])
            // overlap exists hence merge
              last[1] = max(last[1], curr[1]);
            else
            // no overlap
            ans.push_back(curr);
        }
        return ans;
    }
};
