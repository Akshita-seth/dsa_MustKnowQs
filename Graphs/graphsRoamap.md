Day 1 — BFS/DFS Foundations

Flood Fill (126)
Number of Islands (120)
Largest Region in Boolean Matrix (125)
Clone Graph (117)
Rotten Oranges (131) ← multi-source BFS fits here

Day 2 — Grid + State-space BFS

Pacific Atlantic Water Flow (119)
Snake and Ladder (121)
Word Ladder (LC 127)

Day 3 — Cycle Detection + Bipartite

Detect Cycle in Directed Graph (122)
Course Schedule (118)
Check for Bipartite (124)

Day 4 — Topological Sort + SCC

Topological Sorting (128)
Course Schedule II (LC 210)
Strongly Connected Components (127)
Alien Dictionary (LC 269)

Day 5 — Shortest Path

Dijkstra's Algorithm (129)
Network Delay Time (LC 743)
Cheapest Flights Within K Stops (LC 787)

Day 6 — DSU + Bridges + Re-solves

Union-Find / Number of Provinces (130)
Redundant Connection (LC 684)
Accounts Merge (LC 721)
Bridges in a Graph (123)
Re-solve 2-3 Day 3 problems cold


DIJKSTRA'S ALGO EXPLANATION DETAIL

🚦 What is Dijkstra’s Algorithm?
It’s a method to find the shortest path from one starting point (called the source) to all other points (called nodes) in a graph.
A graph here means a collection of points (nodes) connected by lines (edges), where each edge has a weight (like distance, time, or cost).

Think of it like Google Maps:
- Cities = nodes
- Roads = edges
- Road length or travel time = weight

Dijkstra’s algorithm tells you the fastest way to reach every city starting from your home.

🪜 Step-by-Step Explanation
Let’s say you want to go from A to all other places:
1. Initialize distances
- Distance to A = 0 (since you’re already there).
- Distance to all other nodes = infinity (unknown yet).

2. Pick the nearest node not yet visited
- Start with A (distance = 0).

 3. Update neighbors
- For each neighbor of A, calculate:
- New Distance = Distance to A + Edge Weight
- If this new distance is smaller than the previously known distance, update it.

4. Mark A as visited
- Once done, you don’t revisit A.

5. Repeat
- Pick the next closest unvisited node.
- Update its neighbors.
- Continue until all nodes are visited.

At the end, you’ll have the shortest distance from A to every other node.
