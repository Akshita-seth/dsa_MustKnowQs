// Problem: Course Schedule 1
// https://leetcode.com/problems/course-schedule/


// Using BFS Kahn's algo [More starightforward approach than dfs]
// TC: O(V+E), each course and pre-requisite edge is processed once.
// SC: O(V+E), additional space is used for storing adjacency list, indegree and queue.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Each prerequisite pair [a, b] means: to take course a, you must first
        // complete course b.
        // → So we add edge b → a in the adjacency list i.e. it stores the prereq courses to be done as a list for a course.
        // → indegree[a]++ because course a has one more prerequisite.

        // Fill adjacency and in-degree simultaneously
        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i); // pushes the most basic course i.e. no prequisited
                           // needed
        }
        int count = 0; // counts processed nodes

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (auto adjNode : adj[course]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
      // If count < numCourses → cycle exists → impossible to finish all courses.
        return count == numCourses;
    }
};



// Using DFS Approach
// TC: O(V+E), each course and pre-requisite edge is processed once.
// SC: O(V+E), additional space is used for storing adjacency list, stack and recursion depth.

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVis) {
        visited[node] = 1;     // mark as visited
        pathVis[node] = 1;     // mark as part of current recursion stack

        for (auto next : adj[node]) {
            if (!visited[next]) {
                if (dfs(next, adj, visited, pathVis)) 
                    return true; // cycle found
            } else if (pathVis[next]) {
                return true; // back-edge → cycle
            }
        }

        pathVis[node] = 0;     // remove from recursion stack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build graph using adjacency list
        // Each prerequisite pair [a, b] means: to take course a, you must first complete course b.
        // → So we add edge b → a in the adjacency list.
        vector<vector<int>> adj(numCourses);
        for (auto& course : prerequisites) {
            adj[course[1]].push_back(course[0]);
        }

        vector<int> visited(numCourses, 0), pathVis(numCourses, 0);

        // DFS Topological Sort with cycle detection:
        // 1. visited[] marks nodes already processed.
        // 2. pathVis[] (recursion stack) detects cycles: if we revisit a node still in the current DFS path, a cycle exists.
        // 3. If any cycle is found → return false (cannot finish all courses).
        // 4. If no cycle → valid topo order exists → return true.
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVis)) 
                    return false;
            }
        }

        return true;
    }
};
