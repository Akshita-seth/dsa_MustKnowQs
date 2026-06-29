// Problem: Count strongly connected components
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// SCCs → Connected Components in Directed Graph (harder case, requires Kosaraju/Tarjan)
// This is the SCC / Topological Graph Decomposition pattern.

// Think of it like this:
// Provinces = “groups of cities connected ignoring direction.”
// SCCs = “groups of nodes connected considering direction, where you can go back and forth.”

// Standard algorithms:

// Kosaraju’s Algorithm (two DFS passes):
// 1. Do DFS and push nodes onto a stack by finish time. 2. Reverse the graph. 
// 3. Pop nodes from stack, run DFS on reversed graph → each DFS gives one SCC.

// Tarjan’s Algorithm (single DFS with low-link values).
// 1.Perform DFS to record finishing times. 2.Reverse edges of the graph.
// 3.Run DFS in order of decreasing finish time. 4.Each DFS traversal = one SCC.
