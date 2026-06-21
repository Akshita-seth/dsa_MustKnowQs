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
