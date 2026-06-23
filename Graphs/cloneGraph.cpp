// Problem: Clone Graph
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// TC: O(V+E)  Each node is visited exactly once because of the unordered_map.
// For each node, you iterate through all its neighbors. So the total work is proportional to the sum of nodes and edges

// SC: O(V+E) Hashmap (oldToNew): Stores one entry per node → O(V)
// Recursion stack: In the worst case (graph shaped like a long chain), DFS depth = O(V)
// Neighbors storage: Each cloned node has a vector of neighbors, same as the original → O(E)
// 𝑉 = number of nodes in the graph
// 𝐸 = number of edges

// Minimal Concise Solution:

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if (oldToNew.count(node)) return oldToNew[node];
        
        Node* clone = new Node(node->val);
        oldToNew[node] = clone;
        
        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(dfs(nei, oldToNew));
        }
        return clone;
    }
};



// MY SOLUTION

class Solution {
public:
    void cloneDFS(Node* node, map<Node*, Node*>& oldToNew)
    {
        if(oldToNew.find(node) != oldToNew.end())
        return;
        // creating copy if not present in map already
        // Node* newNode = new Node(node->val); 
        // oldToNew[node] = newNode; 
        
        // To Avoid redundant variable creation
        oldToNew[node] = new Node(node->val); 

        for(Node* it:node->neighbors)
        {
            cloneDFS(it, oldToNew);
            newNode->neighbors.push_back(oldToNew[it]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) 
         return nullptr;
        unordered_map<Node*, Node*> oldToNew; 

        cloneDFS(node,oldToNew);
        //return the cloned starting node
        return oldToNew[node];
    }
};
