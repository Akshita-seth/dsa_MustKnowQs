// Problem: Is Graph Bipartite
// https://leetcode.com/problems/is-graph-bipartite/description/

// BEST DEFINITION: Any graph with an odd length cycle cannot be Bipartite
// Any graph with even length cycle or a linear graph is Bipartite

// The “partition into two independent sets” is just a formal way of saying:
// You can split the graph into two groups where edges only go across groups.

// Think of it like trying to color the graph with two colors (say Red and Blue):
// If you can color it so that no two adjacent nodes share the same color → the graph is bipartite.
// If at any point two connected nodes are forced to have the same color → it’s not bipartite.

// It’s a two-coloring problem. If you can consistently assign two colors without conflict, the graph is bipartite. If not, it isn’t.

// Core Idea
// Start from any node, assign it a color (say Red).
// Do a DFS or BFS:
//  - Neighbors must get the opposite color (Blue).
//  - Their neighbors again get Red, and so on.
// If you ever find a neighbor already colored with the same color → conflict → not bipartite.

// USING DFS:
// TC:  O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
// SC: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list.

class Solution {
public: 
    bool dfs(int node, int col, vector<int>& colour, vector<vector<int>>& graph)
    {
        colour[node] = col;

        for(auto adjNode : graph[node])
        {
            if(colour[adjNode] == -1)
            {
                if(dfs(adjNode,1-col,colour,graph) == false)
                  return false;
            }

            else if(colour[adjNode] == colour[node])
              return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // here graph vector is the adjacenecy list itself
        int n = graph.size();
        vector<int> colour(n, -1);

        for(int i=0; i<n; i++)
        {
            if(colour[i] == -1)
            {
                if(dfs(i,0,colour,graph) == false)
                return false;
            }
        }
        return true;
    }
};



// USING BFS:

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0 = red, 1 = blue

        for(int start=0; start<n; start++) {
            if(color[start] == -1) {
                // Start BFS/DFS from this node
                queue<int> q;
                q.push(start);
                color[start] = 0; // arbitrary choice

                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    for(int nbr : graph[node]) {
                        if(color[nbr] == -1) {
                            // Assign opposite color
                            color[nbr] = 1 - color[node];
                            q.push(nbr);
                        } else if(color[nbr] == color[node]) {
                            // Conflict
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
