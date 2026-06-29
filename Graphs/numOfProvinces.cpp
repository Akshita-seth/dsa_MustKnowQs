// Problem: Number of Provinces 
// https://leetcode.com/problems/number-of-provinces/description/

// This is the Connected Components in Undirected Graph pattern.
// You can solve it using:
// DFS/BFS traversal: mark visited nodes, increment count when you start a new traversal.
// Union-Find (Disjoint Set Union): merge connected nodes, count distinct parents.


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
