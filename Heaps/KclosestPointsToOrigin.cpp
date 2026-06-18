// Problem: K closest points to the origin
// https://leetcode.com/problems/k-closest-points-to-origin/submissions/2036975815/

// Heaps Soln:
// TC: O(NlogK), SC: O(K)
// point[0] → an int (safe to multiply).
// points[i] → a vector<int> (not safe to multiply).
// thus this is valid as a helper fn: 
int squaredDis(vector<int>& point) {
    return point[0] * point[0] + 
           point[1] * point[1];
}
// But this is not inside the loop: 
int dist = points[i] * points[i];

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
    
        for(int i=0; i<points.size(); i++)
        {
            int x = points[i][0];
int y = points[i][1];
int dist = x * x + y * y; 

            if(maxHeap.size() < k)
            {
                maxHeap.push({dist, points[i]});
            }
            else{
                if(dist < maxHeap.top().first)
                {
                    maxHeap.pop();
                    maxHeap.push({dist, points[i]});
                }
            }
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};

