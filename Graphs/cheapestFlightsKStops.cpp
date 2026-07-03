// Problem: Cheapest Flights within K stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// The difference between this and Dijkstra is that here, cost improvements are only valid if they happen within the allowed stop count.
// Approach: BFS (layered relaxation up to k stops)
// 1. Build adjacency list of flights (u -> v with cost).
// 2. Use a queue storing {stops, node, cost} to explore level by level.
// 3. At each step, skip if stops > k (cannot exceed allowed stops).
// 4. For each neighbor, if we find a cheaper cost within allowed stops,
//    update distVec[v] and push {stops+1, v, newCost} into the queue.
// 5. After BFS finishes, distVec[dst] holds the cheapest cost within k stops.
// 6. If unreachable, return -1.
//
// Key Idea: This is essentially Bellman-Ford style relaxation using BFS,
// ensuring we only expand paths up to k stops. No need for a 2D dist array,
// since we track best cost per node and prune by stop count.

// TC:  O(N), where the additional log(N) time is eliminated by using a simple queue rather than a priority queue, which is usually used in Dijkstra’s Algorithm. 
// Where N = Number of flights / Number of edges.
// SC: O(|E| + |V|), for the adjacency list, priority queue, and the dist array. Where E = Number of edges (flights.size()) and V = Number of airports.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights)
        {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
        // Distance array to track best cost with stops
        vector<int> distVec(n,1e9);
        distVec[src] = 0;

        // Queue: {stops, node, cost} 
        queue<vector<int>> q;
        q.push({0,src,0});

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int stops = node[0];
            int u = node[1];
            int costU = node[2];

            // If stops exceed limit, skip
            if(stops > k) continue;
            
            // Relax neighbors
            for(auto adjNode: adj[u])
            {
                int v = adjNode.first;
                int wt = adjNode.second;

                if(distVec[v] > costU + wt && stops <= k)
                { 
                    distVec[v] = costU + wt;
                    q.push({stops+1,v,distVec[v]});
                }
            }
        }

        if(distVec[dst] == 1e9)
        return -1;

        return distVec[dst];
    }
};

// queue<pair<int,pair<int,int>>> q;

class Solution
{
public:
    // Method to find the cheapest flight within K stops using BFS
    int CheapestFLight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K)
    {
        // Create the adjacency list to represent airports and flights as a graph
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});  // Add an edge from source to destination with the weight (cost)
        }

        // Create a queue to store the node, its distance from the source, and the number of stops
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});  // Push the source node with 0 stops and 0 cost

        // Create a distance array to store the minimum cost to reach each node
        vector<int> dist(n, 1e9);
        dist[src] = 0;  // The distance from source to itself is 0

        // BFS traversal with a queue to process the nodes
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;  // Number of stops so far
            int node = it.second.first;  // Current node
            int cost = it.second.second;  // Cost to reach the current node

            // If the number of stops exceeds K, continue to the next iteration
            if (stops > K)
                continue;

            // Iterate over all the adjacent nodes (next destinations)
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;  // Next destination node
                int edW = iter.second;  // Cost of the flight to the next destination

                // If a shorter path to the adjacent node is found, update the distance
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;  // Update the distance
                    q.push({stops + 1, {adjNode, cost + edW}});  // Push the new node with updated stops and cost
                }
            }
        }

        // If destination node is unreachable, return -1
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];  // Return the minimum cost to reach the destination
    }
};
