// Problem: Shortest Path in Binary Maze
// 

// Don't use DFS or Dijkstra unnecessarily — BFS is enough here.
// Algorithm Choice: Since all moves have equal cost (1 step), use BFS (not Dijkstra).
// BFS guarantees shortest path in an unweighted graph.

// Check start/end: If either is blocked, return -1.
// Use BFS: All moves cost 1, so BFS guarantees shortest path.
// 8 directions: Include diagonals.
// Visited matrix: Prevent revisiting cells.
// Distance counting: Start at 1 because the starting cell counts as a step.


// TC: Time: O(n^2) — each cell visited once, 8 neighbors checked.
// SC: O(n^2) — visited matrix + BFS queue.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // If start or end is blocked, no path
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // Directions: 8 possible moves
        vector<pair<int,int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        // Queue: {x, y, distance}
        queue<vector<int>> q;
        q.push({0,0,1});
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        visited[0][0] = true;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int x = node[0], y = node[1], dist = node[2];
            if(x == n-1 && y == n-1) return dist;

            for(auto d : dirs) {
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   grid[nx][ny] == 0 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, dist+1});
                }
            }
        }
        return -1;
    }
};


// https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze
// If Given:
// Problem Statement: Given an n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. 
// The path can only be created out of a cell if its value is 1. If the path is not possible between the source cell and the destination cell, then return -1.
// Note: You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of four directions, Up, Down, Left, and Right.

// TC: O(4 * N * M), where N * M are the total cells, and for each cell, we check 4 adjacent nodes for the shortest path length. Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
// SC: O(N * M), 


class Solution {
public:
    // Method to find the shortest path in a grid using BFS
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        
        // Edge Case: if the source is the same as the destination
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        // Create a queue for BFS, storing cells with their distances from source
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Initialize the distance matrix, marking all cells as unvisited initially
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;

        // Push the source cell into the queue with distance 0
        q.push({0, {source.first, source.second}});

        // Define the possible directions (up, right, down, left)
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Start BFS traversal
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Check all 4 adjacent directions
            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Check if the new cell is within bounds and is a valid cell (i.e., 1)
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = 1 + dis;  // Update the distance

                    // If destination is reached, return the distance
                    if (newr == destination.first && newc == destination.second)
                        return dis + 1;

                    // Add the new cell to the queue for further processing
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }

        // If no path is found from source to destination
        return -1;
    }
};
