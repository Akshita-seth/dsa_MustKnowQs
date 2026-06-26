// Problem: Shortest Distance in DAG 
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


// Intuition
// Think of it as "relaxing" the tension on the distance estimate.
// Initially, distances are overestimates. Relaxation gradually tightens them until they reach the true shortest path.
// ➡️ Check if going through a particular edge gives a shorter path to a vertex than what you’ve already recorded. If yes, update it.
// Formally, for an edge (u,v) with weight w, If dist[v] > dist[u] + weight, then set dist[v] = dist[u]+w

// In a DAG, topological order guarantees that when you process a node, all paths leading into it have already been considered.
// By setting dist[src] = 0, you “ignite” the relaxation process from the source.
// As you pop nodes in topo order, relaxation propagates forward along edges, ensuring every reachable node gets the shortest possible distance.

//Processing in Topo Order: When you pop a node u from the stack, you already know its shortest distance is finalized (because no incoming edge from a later node can reduce it — DAG property).
// For each outgoing edge (u → v, wt), you check dist[v] > dist[u] + weight
// If dist[u] was finite (reachable from source), then dist[v] gets updated.
// If dist[u] was still ∞ (unreachable), relaxation does nothing — which is correct, because that path doesn’t exist from source.
// Because topo order ensures edges are processed only after their source node’s distance is finalized, every edge gets relaxed exactly once in the right order.

// DFS topo soln
// TC: O(V+E) , topo sort and relaxation each took O(V+E)
// SC: O(V+E) , Adjacency list + stack + distVec + visited

class Solution {
  public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, stack<int>& st, vector<int>& visited)
    {
        visited[node] = 1;
        for(auto adjNode: adj[node])
        {
            int v = adjNode.first;
            if(!visited[v])
            dfs(v,adj,st,visited);
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // DFS Topo Sort with relaxation of edges
        // ADJ LIST
        vector<vector<pair<int,int>>> adj(V);
        for(auto e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
    //    C-style array of vectors. This works, but it’s less flexible 
    //      vector<pair<int,int>> adj[N];
    // for(int i = 0; i < E; i++) {  // i loop for edges thus i<E
    //     int u = edges[i][0];
    //     int v = edges[i][1];
    //     int wt = edges[i][2];
    //     adj[u].push_back({v, wt});
        
        
        stack<int> st;
        vector<int> visited(V,0);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
             dfs(i,adj,st,visited);
        }
        // Relaxation of edges
        vector<int> distVec(V,1e9);
        distVec[0] = 0; // dist[src] = 0; VERY IMP STEP
        
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            
            for(auto adjNode: adj[u])
            {
                int v = adjNode.first;
                int wt = adjNode.second;
                // dist[u] is what was needed to reach u and then to reach v i.e. u's adjNode is extra wt
                // dist[v] is some previous way of reaching v
                if(distVec[v] > distVec[u] + wt) // relaxation step
                distVec[v] = distVec[u] + wt;
            }
        }
        vector<int> ans(V,-1);
        for(int i=0; i<V; i++)
        {
            if(distVec[i] < 1e9)
            ans[i] = distVec[i];
        }
        return ans;
    }
};


// BFS topo soln:

class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list + indegree
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V, 0);
        
        for(auto e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            indegree[v]++;
        }
        
        // Step 2: Kahn’s Algorithm for Topo Sort (BFS)
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto adjNode : adj[node]) {
                int v = adjNode.first;
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        
        // Step 3: Relax edges in topo order (no guard)
        vector<int> dist(V, 1e9);
        dist[0] = 0; // source = 0
        
        for(int u : topo) {
            for(auto adjNode : adj[u]) {
                int v = adjNode.first;
                int wt = adjNode.second;
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Step 4: Prepare answer (-1 for unreachable)
        vector<int> ans(V, -1);
        for(int i = 0; i < V; i++) {
            if(dist[i] < 1e9) ans[i] = dist[i];
        }
        return ans;
    }
};






// with a micro optimization => A guard if(dist[u] != 1e9) guard.
//  unreachable node in topo order are not processed
class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list + indegree
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V, 0);
        
        for(auto e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            indegree[v]++;
        }
        
        // Step 2: Kahn’s Algorithm for Topo Sort (BFS)
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto adjNode : adj[node]) {
                int v = adjNode.first;
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        
        // Step 3: Relax edges in topo order
        vector<int> dist(V, 1e9);
        dist[0] = 0; // source = 0
        
        for(int u : topo) {
            if(dist[u] != 1e9) { // only relax if reachable
                for(auto adjNode : adj[u]) {
                    int v = adjNode.first;
                    int wt = adjNode.second;
                    if(dist[v] > dist[u] + wt) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        
        // Step 4: Prepare answer (-1 for unreachable)
        vector<int> ans(V, -1);
        for(int i = 0; i < V; i++) {
            if(dist[i] < 1e9) ans[i] = dist[i];
        }
        return ans;
    }
};
