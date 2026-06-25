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
			if (!visited[i])    // since there can be multiple connected components
				{
				if (dfs(i, -1, visited, adj) == true)
					return true;
			}
		}
		return false;
	}
};


// BFS Soln:
//TC: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
//SC: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.


class Solution {
	public:
	bool bfs(int node, vector<int>& visited, vector<vector<int>> & adj)
	{
		queue<pair<int,int>> q;
		// pushing the source node with it's parent in thr queue and marking visited
		q.push({node,-1});
		visited[node] = 1;
		
		while(!q.empty())
		{
		    auto [node, parent] = q.front();
		    q.pop();
		    
		    for(auto it: adj[node])
		    {
		        if(!visited[it])
		         {
		             q.push({it,node});
		             visited[it] = 1;
		         }
		        else if(it != parent)
		         return true;
		    }
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
			if (!visited[i])  // check for multiple connected components
				{
				if (bfs(i, visited, adj) == true)
					return true;
			}
		}
		return false;
	}
};




