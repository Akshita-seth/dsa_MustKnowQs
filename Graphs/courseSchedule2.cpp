// Problem: Course Schedule 2
// https://leetcode.com/problems/course-schedule-ii/


// In Course Schedule II, you must return the actual ordering of courses. 
//That means if a cycle exists, you can’t just return whatever partial order you built — you need to detect the cycle and return an empty vector instead.
// TC: O(V+E), each course and pre-requisite edge is processed once.
// SC: O(V+E), additional space is used for storing adjacency list, queue and ordering array.


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto course: prerequisites)
        {
            // edge is b->a
            int a = course[0], b = course[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> topoOrder;

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty())
        {
            int course = q.front();
            topoOrder.push_back(course);
            q.pop();

            for(auto adjNode: adj[course])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                q.push(adjNode);
            }
        }
        
        if(topoOrder.size() == numCourses)
        return topoOrder;

        // If there’s a cycle, topoOrder.size() < numCourses
        return {};
    }
};


// DFS Soln
// TC: O(V+E), each course and pre-requisite edge is processed once.
// SC: O(V+E), additional space is used for storing adjacency list, stack and recursion depth.



class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVis, stack<int>& st) {
        visited[node] = 1;     // mark as visited
        pathVis[node] = 1;     // mark as part of current recursion stack

        for (auto next : adj[node]) {
            if (!visited[next]) {
                if (dfs(next, adj, visited, pathVis, st)) 
                    return true; // cycle found
            } else if (pathVis[next]) {
                return true; // back-edge → cycle
            }
        }

        pathVis[node] = 0;     // remove from recursion stack
        st.push(node);         // push after exploring all neighbors
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build graph: b → a
        vector<vector<int>> adj(numCourses);
        for (auto& course : prerequisites) {
            adj[course[1]].push_back(course[0]);
        }

        vector<int> visited(numCourses, 0), pathVis(numCourses, 0);
        stack<int> st;

        // Run DFS for all nodes
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVis, st)) {
                    return {}; // cycle detected → no valid order
                }
            }
        }

        // Build topo order from stack
        vector<int> topoOrder;
        while (!st.empty()) {
            topoOrder.push_back(st.top());
            st.pop();
        }
        return topoOrder;
    }
};
