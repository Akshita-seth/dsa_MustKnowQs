// Problem: Flood Fill
// https://leetcode.com/problems/flood-fill/

// Islands: marking visited changes the cell so the DFS condition fails next time.
// Flood fill: Recoloring doesn’t break the condition unless you explicitly guard (orgColor == color in floodFill() or image[sr][sc] != orgColor in dfs() ), 
//otherwise, DFS keeps revisiting and overflows.

// DFS Soln
// TC: O(M*N) each cell visited at most once
// SC: O(M*N) due to recursion in worst case i.e. all cells connected

class Solution {
public:
    void dfs(int sr, int sc, int m, int n, int orgColor, int color, vector<vector<int>>& image)
    {
        // base case imp here since no visited array check
        if(image[sr][sc] != orgColor) return;

        image[sr][sc] = color;

        int dx[4] = {-1, 1, 0, 0};  // imp to initialise the size too while creating array like this
        int dy[4] = {0, 0, -1, 1};
        for(int i=0; i<4; i++)
        {
            int nsr = sr + dx[i];
            int nsc = sc + dy[i];

            if(nsr>=0 && nsr<m && nsc>=0 && nsc<n)
            dfs(nsr, nsc, m, n, orgColor, color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int orgColor = image[sr][sc];
        if(orgColor == color) 
        return image; // to avoid unnecessary recursion

        dfs(sr,sc,m,n,orgColor,color,image);
        return image;
    }
};

// DFS → simpler, but risky for large grids.
// BFS → safer, avoids recursion limits.


// BFS Soln
// TC: O(M*N) each cell visited once
// SC: (M*N) queue can hold all cells in worst case

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int orgColor = image[sr][sc];
        if (orgColor == color) return image; // guard

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == orgColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};
