// Problem: Max Area of Island or Largest Region in Boolean Matrix
// https://leetcode.com/problems/max-area-of-island/



// DFS Soln (Preferred for matix)
// TC: O(N) every cell visited at most once
// SC: O(M*N) recursion stack


class Solution {
public:
    int dfs(int m, int n, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        visited[i][j] = 1;
        int area = 1; // counts current cell

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k=0; k<4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1 && !visited[ni][nj])
             area += dfs(m,n,ni,nj,grid,visited);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));
        int maxArea = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j]) {
                int area = dfs(m,n,i,j,grid,visited);
                maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};



// BFS:
// TC: O(M*N) — each cell visited once.
// SC: O(M*N) worst case (queue + visited).


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int maxArea = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        area++;  // count each cell in this island

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] == 1 && !visited[nr][nc]) {
                                visited[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
