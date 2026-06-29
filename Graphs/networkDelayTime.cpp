// Problem: Network Delay Time
// https://leetcode.com/problems/network-delay-time/submissions/2049999101/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list with weights
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &t: times) {
            int u = t[0], v = t[1], wt = t[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Distance vector initialized to infinity
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, k});

        // Step 3: Dijkstra’s Algorithm
        while(!minHeap.empty()) {
            int distU = minHeap.top().first;
            int u = minHeap.top().second;
            minHeap.pop();

            // Skip outdated entries
            if(distU > dist[u]) continue;

            for(auto &edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                if(dist[v] > distU + wt) {
                    dist[v] = distU + wt;
                    minHeap.push({dist[v], v});
                }
            }
        }

        // Step 4: Find maximum time
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1; // unreachable node
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
