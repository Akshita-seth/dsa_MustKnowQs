//Problem: Weighted Sum of Tree
// https://leetcode.com/problems/weighted-sum-of-a-tree/description/

// DFS (Recursive)

// Build adjacency list.
// Traverse from root, compute depth of each node.
// Track max depth (height).
// Compute weighted sum.
// Time: O(n), Space: O(n)

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        
        // Build adjacency list
        for(int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }
        
        vector<int> depth(n, 0);
        int h = 0;
        
        // DFS to compute depth
        function<void(int,int)> dfs = [&](int node, int d) {
            depth[node] = d;
            h = max(h, d);
            for(int child : tree[node]) {
                dfs(child, d+1);
            }
        };
        
        dfs(0, 1); // root depth = 1
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return sum;
    }
};


// BFS (Iterative)

// Use a queue starting from root.
// Assign depth level as you pop nodes.
// Track max depth.
// Compute weighted sum.
// Same complexity: O(n).



class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> tree(n);

        // Build adjacency list
        for(int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> depth(n, 0);
        queue<pair<int,int>> q; // {node, depth}
        q.push({0, 1}); // root at depth 1
        int h = 0;

        // BFS traversal
        while(!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            depth[node] = d;
            h = max(h, d);
            for(int child : tree[node]) {
                q.push({child, d+1});
            }
        }

        // Weighted sum
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return sum;
    }
};






