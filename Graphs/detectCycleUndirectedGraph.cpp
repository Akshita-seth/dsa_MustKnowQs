// Problem: Detect Cycle in an Undirected Graph
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs
// https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs


// DFS Soln:
// TC: O(V+E) each node and edge visited once
// SC: O(V+E) adjacency list, recursion stack and visited array


class Solution {
	public:
	bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>> & adj)
	{
		visited[node] = 1;
		
		for (auto it : adj[node])
			{
			if (!visited[it])
				{
				if (dfs(it, node, visited, adj))
					return true;
			}
			else if (it != parent)
				return true;
		}
		return false;
	}
	
	bool isCycle(int V, vector<vector<int>> & edges) {
		// DFS Approach
		vector<vector<int>> adj(V);
		for (auto& e:edges)
			{
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		vector<int> visited(V, 0);
		
		for (int i = 0; i<V; i++)
			{
			if (!visited[i])
				{
				if (dfs(i, -1, visited, adj) == true)
					return true;
			}
		}
		return false;
	}
};


// BFS Soln:

