// Dijkstra's Algorithm
// Problem: Shortest path in weighted undirected graph
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// for min-heap no customComparatpor needed
// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// greater<pair<int,int>> is already defined in the STL: it compares pairs lexicographically (first element, then second).
// Since in Dijkstra we push (distance, node), the smallest distance automatically comes to the top.
// Doesn't work fro neative weights

// TC:


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // Build Adj list
        vector<vector<pair<int,int>>> adj(V);
        for(auto e: edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt}); // since undirected
        }
        // Min-Heap {dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> distVec(V,1e9);
        
        distVec[src] = 0;
        minHeap.push({0,src});
        
        // Dijkstra's Loop
        while(!minHeap.empty())
        {
            int u = minHeap.top().second;
            int distU = minHeap.top().first;
            minHeap.pop();
            
            for(auto adjNode: adj[u])
            {
                int v = adjNode.first;
                int wt = adjNode.second;
                
                // no need to visiste comfirmed long paths for that node
                if (distU > distVec[u]) continue; // without this not all test acses wer getting passed
                
                if(distVec[v] > distU + wt)
                  {
                      distVec[v] = distU + wt;
                      minHeap.push({distVec[v],v}); // {dist,node} pair in heap
                  }
            }
        }
        return distVec;
    }
};
