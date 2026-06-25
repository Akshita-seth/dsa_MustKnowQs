// Problem: Topo Sort using DFS
// https://www.geeksforgeeks.org/problems/topological-sort/1


//Intuition
// DFS explores nodes deeply; when a node finishes (all its descendants are processed), you push it onto a stack.
// This “finish time” captures dependency: a node is placed only after all nodes it points to are done.
// Finally, reversing the stack gives the correct topological order — parents before children, respecting all edges.
// 👉 Think of it as: “DFS ensures you don’t schedule a task until all tasks depending on it are completed. The reverse of finishing times is the valid schedule.”

// TC: O(V + E), each vertex is visited exactly once, and each directed edge is explored exactly once during the DFS traversal. The cost of visiting all vertices is O(V) and the cost of exploring all edges is O(E). Since both happen sequentially and not nested, the total time complexity is O(V + E).
// For example, if V = 6 and E = 6, the DFS will make exactly 6 vertex visits and 6 edge explorations, leading to a total of O(6 + 6) = O(12), which simplifies to O(V + E).
// SC: O(V + E), The space complexity comes from three parts: the adjacency list (which stores all vertices and edges, taking O(V + E) space), the visited array (O(V) space), and the recursion stack (O(V) in the worst case for a DFS if the graph is like a chain). The stack used to store the topological order will also take O(V) space. Therefore, the dominant space usage is O(V + E). 
// For example, if V = 6 and E = 6, the adjacency list will store all 6 vertices and 6 edges (O(12) space), the visited array takes O(6), and the recursion stack may take up to O(6) in the worst case, keeping the total within O(V + E).


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


// Validation check part of code for topo sort

vector<int> position;
    for(int i=0; i<V; i++)
    position[topo[i]] = i;
    
    for(auto e:edges)
    {
        if(position[e[0]] > position[e[1]]);
        return false;
    }
    return true;



// ✅ DFS Topological Sort with Cycle Check

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
