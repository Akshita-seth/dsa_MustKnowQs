// Problem: Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/description/



// Using DFS Detect Cycle in Directed Graph approach of visited and pathVisited
// TC: O(V+E) each edge and vertex explored once 
// SC: O(V+E) visited, pathVis & safe -> O(V) each; recursion stack-> O(V); adj list-> O(V+E)


class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVis, vector<int>& safe)
    {
        visited[node] = 1;
        pathVis[node] = 1;

        for(auto adjNode: graph[node])
        {
            if(!visited[adjNode])
             {
                if(dfs(adjNode,graph,visited,pathVis,safe))
                {
                    safe[node] = 0; // mark current node unsafe if cycle found
                    return true;
                }
             }
            else if(pathVis[adjNode] == 1)
            {
                safe[node] = 0;    // back-edge → cycle (node connected to cycle)
                return true;
            }
        }
        pathVis[node] = 0;
        safe[node] = 1;  // no cycle -> safe
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // DFS detect cycle approach
        int V = graph.size();
        vector<int> visited(V,0);
        vector<int> pathVis(V,0);
        vector<int> safe(V,0);

        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            dfs(i,graph,visited,pathVis,safe);
        }
        vector<int> safeNodes;
        for(int i=0; i<V; i++)
        {
            if(safe[i] == 1)
            safeNodes.push_back(i);
        }
        return safeNodes;
    }
};




// Topo Sort BFS approach
// TC:  O(V + E) + O(N log N), [building adjRev & performing BFS and sorting safeNodes]
// SC: O(V+E), [indegree, queue & safeNodes O(V) each and adjRev O(V+E)] 


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V,0);
        for(int i=0; i<V;i++)
        {
            // origially i -> it
            // reversed it -> i
            for(auto it: graph[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> safeNodes;
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto adjNode: adjRev[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                q.push(adjNode);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};




