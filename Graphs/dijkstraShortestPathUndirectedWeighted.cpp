// Dijkstra's Algorithm
// Problem: Shortest path in weighted undirected graph
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// for min-heap no customComparatpor needed
// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// greater<pair<int,int>> is already defined in the STL: it compares pairs lexicographically (first element, then second).
// Since in Dijkstra we push (distance, node), the smallest distance automatically comes to the top.
// Doesn't work fro neative weights

// TC: O(ElogV) as each edge leads to at most one insertion in the priority queue, which takes log V time.
// SC: O(V + E), due to the distance array and adjacency list storing all vertices and edges.

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


// USing Set => st.erase() can be done 

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
        // Set used {dist,node}
        set<pair<int,int>> st;
        vector<int> distVec(V,1e9);
        
        distVec[src] = 0;
        st.insert({0,src});
        
        // Dijkstra's Loop
        while(!st.empty())
        {
            // no top access here, iterators work here
            auto it = *(st.begin()); // st.begin() gives iterator thus * => value at the iterator
            
            int u = it.second;
            int distU = it.first;
            st.erase(it); // no pop here, its erase
            
            for(auto adjNode: adj[u])
            {
                int v = adjNode.first;
                int wt = adjNode.second;
                
                // no need to visit comfirmed long paths for that node
                if (distU > distVec[u]) continue; // without this not all test acses were getting passed
                
                if(distVec[v] > distU + wt)
                  {
                      //if already some path exist then remove it as it isnlonger than the new encountered one
                      if(distVec[v] != 1e9) 
                      {
                          st.erase({distVec[v],v});
                      }
                      distVec[v] = distU + wt;
                      st.insert({distVec[v],v}); // {dist,node} pair in set
                  }
            }
        }
        return distVec;
    }
};
