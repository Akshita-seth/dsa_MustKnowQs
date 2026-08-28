// Problem: Rotting Oranges
//



// BFS: Grid-Based BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all initially rotten oranges into the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges, return 0 immediately
        if(fresh == 0) return 0;

        int minutes = -1;
        vector<int> dir = {0,1,0,-1,0}; // 4-directional movement

        // Step 2: BFS traversal
        while(!q.empty()) {
            int size = q.size();
            minutes++;
            for(int k = 0; k < size; k++) {
                auto [x, y] = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = x + dir[d], ny = y + dir[d+1];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // rot the fresh orange
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Step 3: If fresh oranges remain, return -1
        return fresh == 0 ? minutes : -1;
    }
};
