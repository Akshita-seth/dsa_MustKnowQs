// Problem: detect Cycle in a Directed Graph
// https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// DFS Soln:
// TC: O(V+E)+O(V) , visit each vertex once and traverse each edge once. There can be at most V components. So, another O(V) time complexity.
// where V = no. of nodes and E = no. of edges. 
// SC: O(2V + O(V) ~ O(2V): O(2V) for two visited arrays and O(V) for recursive stack space.

class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, int visited[], int pathVis[])
    {
        visited[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjNode : adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode,adj,visited,pathVis) == true)
                 return true;
            }
             else if(pathVis[adjNode] == 1)
               {
                   return true;
               }
        }
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        int visited[V] = {0};
        int pathVis[V] = {0};
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
             {
                 if (dfs(i,adj,visited,pathVis)) 
                 return true;
             }
        }
        return false;
    }
};

// BFS doesn’t naturally track recursion paths. Instead, you rely on topological sorting
// Both DFS and BFS run in O(V+E) time.
// DFS is preferred because it uses only O(V) space and directly detects cycles via back edges.
// BFS (via topological sort) is more indirect, heavier on space, and less intuitive for cycle detection.

