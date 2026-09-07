// Problem: Number of Provinces 
// https://leetcode.com/problems/number-of-provinces/description/

// This is the Connected Components in Undirected Graph pattern.
// You can solve it using:
// DFS/BFS traversal: mark visited nodes, increment count when you start a new traversal.
// Union-Find (Disjoint Set Union): merge connected nodes, count distinct parents.


//Component-wise calculation using DFS/BFS
// TC: O(V+E), we visit every node and for every node we visit all of its neighbours in the DFS traversal.
// SC: O(V), for storing visited array and auxiliary stack space.


class Solution {
private:
    // Function to perform DFS traversal
    void dfs(int node, vector<int> adjList[], int visited[]) {
        // Mark current node as visited
        visited[node] = 1;

        // Visit all adjacent unvisited nodes
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    // Function to count number of connected components
    int numProvinces(vector<vector<int>> adj, int V) {
        // Create adjacency list from adjacency matrix
        vector<int> adjList[V];

        // Convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Ignore self-loops
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Array to keep track of visited nodes
        int visited[V] = {0};

        // Count of connected components
        int count = 0;

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            // If node is not visited
            if (!visited[i]) {
                // Perform DFS and increment count
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
};



//Disjoint set approach:
// TC: O(N^2) [i, j loop in findCircNum fn] + O(alpha) which is constant 
// SC: O(n) -> rank or size and parent

class DisjointSet{
    public:
    vector<int> rank, size, parent;
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0; i<n; i++)
        parent[i] = i;
    }
    
    int findUPar(int node)
    {
        if(parent[node] == node)
        return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);

        if(ulp_u == ulp_v)
        return;

        if(rank[ulp_u] < rank[ulp_v])
        parent[ulp_u] = ulp_v; 
        else if(rank[ulp_v] < rank[ulp_u])
        parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        } 
    }
    void unionBySize(int u, int v)
    {
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);

        if(ulp_u == ulp_v)
        return;

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else 
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;

        DisjointSet ds(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(ds.findUPar(i) == i)
            provinces++;
        }

        return provinces;
    }
};
