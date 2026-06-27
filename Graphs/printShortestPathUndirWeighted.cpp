// Problem: Print Shortest Path in a graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1


// Using Dijkstra's soln with parent[] that stores where each node is coming from
// TC: O(E logV) i.e. here O(mlogn) and another + O(n) for path construction
// SC: O(m+n) where adj lost is O(m+n) , distVec, parent, minHeap, path all O(n) each

// the modification fixed the termination condition of the path reconstruction loop. 
// Using -1 makes the source detection explicit and avoids the logical gap that was causing wrong outputs.
// Old approach: “self‑parenting” (parent[i] = i) → fragile stop condition, required hacks.
// New approach: “sentinel parent” (parent[i] = -1) → clean stop condition, source included automatically, consistent across all cases.

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto e: edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt}); // undirected graph
        }
        
        // Min-heap {dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> distVec(n+1,1e9);
        vector<int> parent(n+1,-1);
        
        distVec[1] = 0;
        minHeap.push({0,1});
        
        // Dijkstra's loop
        while(!minHeap.empty()) {
            int u = minHeap.top().second;
            int distU = minHeap.top().first;
            minHeap.pop();
            
            for(auto adjNode: adj[u]) {
                int v = adjNode.first;
                int wt = adjNode.second;
                
                if(distU + wt < distVec[v]) {
                    distVec[v] = distU + wt;
                    minHeap.push({distVec[v],v});
                    parent[v] = u;
                }
            }
        }
        
        if(distVec[n] == 1e9) return {-1}; // no path
        
        // Reconstruct path
        vector<int> path;
        int node = n;
        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        
        // Final answer: distance first, then path nodes
        vector<int> ans;
        ans.push_back(distVec[n]);
        for(int x : path) ans.push_back(x);
        return ans;
    }
};
