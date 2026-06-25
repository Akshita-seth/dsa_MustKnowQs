// Problem: Shortest Path in Undirected graph with unit weight
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1


// BFS visits all nodes level-by-level (same level first), which ensures we always get the shortest path in terms of number of edges.
// TC: O(E)+O(V+2E)+(V) ~ O(V+2E), traversing E edges for building adj list, BFS traversal- every node and edge traversed once, storing in resultant 
// SC: O(V+2E)for adj list(Stores all edges thus E plus undirected here thus 2E ) + O(V) for each dist[], queue[], result 

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(src);
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adj[node])
            {
                if(dist[adjNode] > dist[node] + 1)
                {
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                }
            }
        }
        vector<int> ans(V, -1);
        for(int i=0; i<V; i++)
        {
            if(dist[i] < INT_MAX)
            ans[i] = dist[i];
        }
        return ans;
    }
};

// In above soln, Queue only stores node, distance can be taken from dist vector


// In below soln, queue storing pairs {node, dist}

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>> q; // {node, dist}
        q.push({src, 0});
        
        vector<int> distVec(V, INT_MAX);
        distVec[src] = 0;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(auto adjNode: adj[node])
            {
                if(distVec[adjNode] > dist + 1)
                {
                    distVec[adjNode] = dist+1;
                    q.push({adjNode, dist+1});
                }
            }
        }
        vector<int> ans(V, -1);
        for(int i=0; i<V; i++)
        {
            if(distVec[i] < INT_MAX)
            ans[i] = distVec[i];
        }
        return ans;
    }
};
