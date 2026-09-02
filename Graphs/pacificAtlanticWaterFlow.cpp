// Problem: Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/


// If NESTED LOOP USED
for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
        dfs(m,n,i,j,heights,pacific);
        dfs(m,n,i,j,heights,atlantic);
    }
}
// This means you’re starting DFS from every cell in the grid, not just the borders.
// That forces all cells to eventually be marked reachable in both matrices, because DFS will expand outward from them.
// The result becomes the entire grid (or at least much larger than expected), not just the correct intersection.


// DFS directly expresses “mark this cell, then explore its neighbors” — exactly the logic you want.
// BFS would work too, but it adds unnecessary queue mechanics when recursion already handles the expansion elegantly.


// TC: O(M*N) Each DFS visits a cell at most once per ocean. Even though you start DFS from multiple border cells, the visited check ensures you don’t re‑explore cells.
// SC:O(M*N) 2 reachability matrices, recursion stack, result matrix


class Solution {
public:
    void dfs(int m, int n, int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& reachability)
    {
        reachability[i][j] = true;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k=0; k<4; k++)
        {
            int ni = i+dx[k];
            int nj = j+dy[k];

            if(ni>=0 && ni<m && nj>=0 && nj<n && !reachability[ni][nj] && heights[ni][nj] >= heights[i][j])
            dfs(m,n,ni,nj,heights,reachability);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));

        // Iterating row-wise -> Left and right of the island covered   // NO NEED TO MARK BORDER CELLS AS TRUE BEFORE DFS, DFS DOES IT ITSELF
        for(int i=0; i<m; i++)
        {
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        // Iterating rcolumn-wise -> Top and bottom of the island covered
        for(int j=0; j<n; j++)
        {
            pacific[0][j] = true;
            atlantic[m-1][j] = true;
        }                                                  // TILL HERE NO NEED
        
        // CALL DFS FOR VISITING THE ISLAND CELLS AND BORDER NEIGHBOURS
        for(int j=0; j<n; j++)
        {
          dfs(m,n,0,j,heights,pacific);
          dfs(m,n,m-1,j,heights,atlantic);
        }
        for(int i=0; i<m; i++)
        {
          dfs(m,n,i,0,heights,pacific);
          dfs(m,n,i,n-1,heights,atlantic);
        }
                
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pacific[i][j] == true && atlantic[i][j] == true)
                result.push_back({i,j});
            }
        }
        return result;
    }
};


