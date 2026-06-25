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



// Today
for course schedule 1 i think he intution is
here the u before v thing in topo is kina reversed here bi will be u and ai as v
next i thunk a validity check of the topo sort created have to be done in order to be able to return true or false for canFinish()
You’ve got the right intuition — let’s sharpen it step by step:

1. Edge direction in prerequisites
In Course Schedule I, each pair 
[
𝑎
𝑖
,
𝑏
𝑖
]
 means:

To take course 
𝑎
𝑖
, you must first complete course 
𝑏
𝑖
.

So the edge is 
𝑏
𝑖
→
𝑎
𝑖
.

That’s why it feels “reversed” compared to the usual 
𝑢
→
𝑣
 phrasing in topological sort examples — here 
𝑢
=
𝑏
𝑖
 (prerequisite), 
𝑣
=
𝑎
𝑖
 (dependent).

2. Why topo sort works here
A valid topological ordering exists iff the graph has no cycle.

If you can produce such an ordering, it means you can line up all courses respecting prerequisites.

If a cycle exists, no ordering is possible → you cannot finish all courses.

3. Validity check
After running topo sort (via Kahn’s BFS or DFS stack), check the length of the ordering:

If topo.size() == numCourses, return true.

Otherwise (some nodes couldn’t be placed because of a cycle), return false.

4. Putting it together
Build adjacency list with edges 
𝑏
𝑖
→
𝑎
𝑖
.

Run topo sort (Kahn’s algorithm is often clearer here since it directly uses indegree).

At the end:

cpp
return topo.size() == numCourses;
That’s the validity check you mentioned — it ensures all courses are schedulable.

👉 Directionally:

Think of bi as the source (prerequisite), ai as the destination (dependent).

The true/false comes from whether your topo sort covers all nodes.

Would you like me to sketch a dry run with a small example (say 4 courses, with edges like 
[
1
,
0
]
,
[
2
,
1
]
,
[
3
,
2
]
) so you can see how the queue evolves and why the validity check works?

i dont have to do this check ?: If a cycle exists, no ordering is possible → you cannot finish all courses.
if not, how is int incorportaed within topo sort logic? ik topo sort is fro DAG only so what will happen if a cycle exeist in the input pls elaborate
Great question — this is exactly where the cycle detection aspect is “baked into” the topological sort logic itself. Let’s break it down clearly:

🔹 What happens if a cycle exists?
Topological sort only works for DAGs (Directed Acyclic Graphs).

If a cycle exists, there is no valid ordering because some courses depend on each other in a loop.

Example: 
[
0
,
1
]
,
[
1
,
0
]
 → course 0 needs 1, and 1 needs 0. Impossible.

🔹 How cycle detection is incorporated
Kahn’s Algorithm (BFS topo sort):

Start with nodes of indegree = 0 (no prerequisites).

Each time you remove a node, you reduce indegree of its neighbors.

If a cycle exists, some nodes will never reach indegree 0.

At the end, if your topo list size < numCourses → cycle detected → return false.

DFS-based topo sort:

Use visited[] and pathVis[] (recursion stack).

If during DFS you revisit a node that’s already in the current recursion stack (pathVis), you’ve found a cycle.

That’s the built-in detection: you abort and return false.

🔹 Why you don’t need an extra check
The “validity check” you mentioned (topo.size() == numCourses) is the cycle check itself in BFS.
In DFS, the cycle check is the pathVis detection.

So you don’t separately check “is there a cycle?” — the algorithm’s mechanics expose it:

BFS → leftover nodes with indegree > 0.

DFS → recursion stack hit.

🔹 Intuition summary
No cycle → topo sort succeeds → all courses scheduled.

Cycle → topo sort stalls or detects back-edge → cannot finish.

👉 That’s why the LeetCode problem’s canFinish() is essentially:

Build graph.

Run topo sort (BFS or DFS).

Return true if all courses are covered, else false.

Would you like me to dry run a cycle case (say 2 courses with edges 
[
0
,
1
]
,
[
1
,
0
]
) in both BFS and DFS, so you can see exactly how the algorithm “gets stuck” and why the check naturally fails?

i am not asking specific to this qs. i am asking about n=basic topo sort voa dfs and bfs what will happen if cycke exists? how is it handeked? or is it not> the input is assumed acyclic? and if  it is not assumed.. do we have to add a cgeck formit and how?
below are my dds and bfs topo codes pls answer each qs

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, int visited[], stack<int>& st)
    {
        visited[node] = 1;
        
        for(auto adjNode : adj[node])
        {
            if(!visited[adjNode])
              dfs(adjNode,adj,visited,st);
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // DFS approach
        vector<vector<int>> adj(V);
        for(auto e:edges)
          adj[e[0]].push_back(e[1]);
         
         int visited[V] = {0};
         // or vector<int> visited(V, 0);
         stack<int> st;
         
         for(int i=0; i<V; i++)
         {
             if(!visited[i])
               dfs(i,adj,visited,st);
         }
        vector<int> topo;
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
    
    return topo;
    }
};

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
Perfect — let’s tackle your questions one by one, using your DFS and BFS topo sort codes as the base.

🔹 1. Is topo sort input assumed acyclic?
In theory: Yes, the definition of topological sort assumes the graph is a DAG (Directed Acyclic Graph).

In practice: Inputs may contain cycles, so robust implementations must detect them. Otherwise, your code will happily produce a “topo order” that isn’t valid.

🔹 2. What happens if a cycle exists?
DFS version (your code)
Current code only uses a visited[] array.

If a cycle exists, DFS will still push nodes onto the stack, but the order is meaningless because you never detect back-edges.

Example: Graph with edges 0→1, 1→0. DFS visits 0, then 1, then pushes both. You’ll get [1,0] or [0,1], but that’s not a valid topo order.

Fix: Add a pathVis[] (recursion stack) check:

cpp
bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVis, stack<int>& st) {
    visited[node] = 1;
    pathVis[node] = 1;
    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            if (dfs(adjNode, adj, visited, pathVis, st)) return true; // cycle
        } else if (pathVis[adjNode]) {
            return true; // back-edge → cycle
        }
    }
    pathVis[node] = 0;
    st.push(node);
    return false;
}
If this returns true, you abort and report cycle.

BFS version (Kahn’s Algorithm)
Your code is almost complete.

If a cycle exists, some nodes will never reach indegree = 0, so they never enter the queue.

At the end, topo.size() < V.

That’s the built-in cycle detection.

Fix: Add a check:

cpp
if (topo.size() != V) {
    // cycle exists
}
🔹 3. Do we need an explicit cycle check?
DFS topo sort → Yes, you must add explicit cycle detection (via recursion stack).

BFS topo sort → No extra check needed; the topo.size() == V condition is the cycle check.

🔹 4. Summary
DFS topo sort: Without cycle check, it will still output something, but it may be invalid. You must add pathVis[].

BFS topo sort (Kahn’s): Cycle detection is implicit — if not all nodes are processed, there’s a cycle.

General rule: Topo sort is only valid if the graph is acyclic. If not, you must detect and handle cycles.

👉 So:

Your DFS code needs modification to handle cycles.

Your BFS code already has cycle detection “built in” — just check the size of the result.

Would you like me to dry run both codes on a cycle example (say V=2, edges=[[0,1],[1,0]]) so you can see exactly how DFS fails without pathVis and how BFS naturally detects the cycle?

give my mofified code with the checks added
Here’s your modified code with proper cycle detection added for both DFS and BFS approaches:

✅ DFS Topological Sort with Cycle Check
cpp
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVis, stack<int>& st) {
        visited[node] = 1;
        pathVis[node] = 1;  // mark node in current recursion stack

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (dfs(adjNode, adj, visited, pathVis, st)) 
                    return true; // cycle found
            } else if (pathVis[adjNode]) {
                return true; // back-edge → cycle
            }
        }

        pathVis[node] = 0;  // remove from recursion stack
        st.push(node);
        return false;
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto e : edges)
            adj[e[0]].push_back(e[1]);

        vector<int> visited(V, 0), pathVis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVis, st)) {
                    // cycle detected → return empty topo order
                    return {};
                }
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};


// ✅ BFS (Kahn’s Algorithm) with Cycle Check
// If there’s a cycle, some nodes never reach indegree = 0 → topo.size() < V.
// If the queue is empty at the start i.e. no node will indegree 0 (or becomes empty before all nodes are processed), the loop ends naturally.


class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto e : edges)
            adj[e[0]].push_back(e[1]);

        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i])
                indegree[it]++;
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto adjNode : adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        // cycle check: if topo size < V, cycle exists
        if ((int)topo.size() != V) {
            return {}; // return empty order if cycle detected
        }

        return topo;
    }
};
