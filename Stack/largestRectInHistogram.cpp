// Problem: Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/


// BFS:  TC: O(N^2)


// 1st version: using curr 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        // Consider every bar one by one
        for(int i=0; i<n; i++)
        {
            int curr = heights[i];
            int width = 1;

            // expanding towards left
            // Traverse left while we have a greater height bar
            for(int j=i-1; j>=0 && heights[j] >= heights[i]; j--)
            curr += heights[i];
            // expanding right
            // Traverse right while we have a greater height bar
            for(int j=i+1; j<n && heights[j] >= heights[i]; j++)
            curr += heights[i];

            ans = max(ans,curr);
        }
        return ans;
    }
};

// 2nd version: using width and ch
int getMaxArea(vector<int> &arr){
    int n = arr.size();
    int res = 0;

    for(int i = 0; i < n; i++){
        int h = arr[i];
        int width = 1;

        // expand left
        for(int j = i-1; j >= 0 && arr[j] >= h; j--) width++;

        // expand right
        for(int j = i+1; j < n && arr[j] >= h; j++) width++;

        res = max(res, h * width);
    }
    return res;
}

