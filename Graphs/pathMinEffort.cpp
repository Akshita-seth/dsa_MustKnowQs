// Problem: Path with Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/

// Using Dijkstra's to find minimum out of maximum efforts on each path
// TC: O(4 * N * M * log(N * M)), where N * M are the total cells, for each of which we check 4 adjacent nodes for the minimum effort and 
// an additional log(N * M) for insertion-deletion operations in a priority queue. Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
// SC: O(N * M), where N * M is the distance matrix containing N * M cells, plus the priority queue in the worst case containing all the nodes (N * M).


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> dist (r,vector<int>(c,1e9));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0,0,0});

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!minHeap.empty())
        {
            vector<int> top = minHeap.top();
            int diff = top[0];
            int x = top[1];
            int y = top[2];
            minHeap.pop();
            
            if(x == r-1 && y == c-1)
            return diff;

            for(int k=0; k<4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < r && nx >=0 && ny >= 0 && ny < c)
                {
                   //int wt = abs(heights[nx][ny] - heights[x][y]);
                    int newEffort = max(diff, abs(heights[nx][ny] - heights[x][y]));
                    if(dist[nx][ny] > newEffort)
                    {
                        dist[nx][ny] = newEffort;
                        minHeap.push({newEffort,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
};
