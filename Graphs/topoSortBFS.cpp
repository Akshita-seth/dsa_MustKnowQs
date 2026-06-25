// Problem: Topo Sort BFS => Kahn's Algo
// https://www.geeksforgeeks.org/problems/topological-sort/1


// TC: O(V + E) because we visit each vertex exactly once and process all outgoing edges from each vertex exactly once. 
// The in-degree calculation takes O(E), and each vertex is enqueued and dequeued exactly once in O(V). Thus, total time is linear in the sum of vertices and edges.
// SC: O(V + E) because we store the adjacency list which takes O(E) space, the in-degree array which takes O(V), the queue which can store up to O(V) vertices at a time, 
// and the topological order array which takes O(V). Overall, the space requirement is proportional to the size of the graph.

//You look for nodes with no incoming edges (in-degree = 0) since they have no prerequisites and can safely come first. Removing them reduces the in-degree of their neighbors, 
//gradually unlocking more nodes. Repeating this process builds a valid topological order, or reveals a cycle if some nodes never reach in-degree zero.


class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// BFS approach, Kahn's Algo
		vector<vector<int>> adj(V);
		for (auto e:edges)
			adj[e[0]].push_back(e[1]);
		
		vector<int> indegree(V, 0);
		
		// Method 1: traversing in the adj list
		for (int i = 0; i<V; i++)
			{
			for (auto it: adj[i])
				indegree[it]++;
		}
		
		// Method 2: count number of incoming edges
		//vector<int> indegree(V, 0);
		//for (auto e : edges) {
		//	indegree[e[1]]++;
		//}
		
		queue<int> q;
		vector<int> topo;
		
		for(int i=0; i<V; i++)
		{
		    if(indegree[i] == 0)
		     q.push(i);
		}
		
		while(!q.empty())
		{
		    int node = q.front();
		    topo.push_back(node);
		    q.pop();
		    
		    for(auto adjNode: adj[node])
		    {
		        indegree[adjNode]--;
		        if(indegree[adjNode] == 0)
		        q.push(adjNode);
		    }
		}
		
		return topo;
	}
};
