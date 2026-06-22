// Problem: Number of Islands
// https://leetcode.com/problems/number-of-islands/
// https://www.geeksforgeeks.org/dsa/find-the-number-of-islands-using-dfs/

// TC: O(m·n) since each cell is visited once.
// SC: O(m·n) for the visited matrix plus recursion stack in worst case.

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<int>>& visited)
{
    visited[i][j]=1;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int k=0; k<4; k++)
    {
        int ni = i+dx[k];
        int nj = j+dy[k];

        if(ni>=0 && ni<m && nj >=0 && nj<n && grid[ni][nj]=='1' && !visited[ni][nj])
         dfs(ni, nj, m, n, grid, visited);
    }


}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int islands=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    islands++;
                    dfs(i,j,m,n,grid,visited);
                }
            }
        }
        return islands;
    }
};

// Problem-> Forgot the importance of queue in BFS
//BFS: we need our own structure to remember “neighbors to visit later.” That’s the queue.
//When you push (i, j) into the queue:
//You mark it visited (so you won’t push it again).
//You process it in FIFO order — meaning you explore all neighbors of the current cell before moving deeper.
//This guarantees a level‑by‑level exploration (breadth‑first).


// BFS soln with visited array


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int islands = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] == '1' && !visited[nr][nc]) {
                                visited[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};


// BFS without visited array, not advised in interviews but u should know how flipping 1's in grid to 0 when visited saves the memory of extra visisted matrix. 
// the grid values with 0 i.e. water are not traversed by the loop; similarly, the grid values with 0 i.e. already visited ones will also not be traversed again.
    
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {   // found new island
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';      // mark visited immediately

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0';  // mark visited
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
