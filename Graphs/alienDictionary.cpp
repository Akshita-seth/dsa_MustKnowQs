// Problem: Alien Dictionary
// https://www.geeksforgeeks.org/problems/alien-dictionary/1


// Topo Sort BFS Approach

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        // Step 1: Build Adj List for 26 letters (since Num of letetrs not given/mentioned)
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26,false); // tracks which chars are actually present
        
        // Mark all chars that actually appear in words
        for(auto w: words)
        {
            for(char c:w)
            present[c - 'a'] = true;
        }
        
        // Step 2: Build directed graph edges
        for(int i=0; i< n-1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];
            int len = min(w1.length(), w2.length());
            
            bool found = false;
            for(int j=0; j<len; j++)
            {
                if(w1[j] != w2[j]) // only the first mismatch matters
                {
                    // int u = w1[j] - 'a';
                    // int v = w2[j] - 'a';
                    // adj[u].push_back(v);
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    indegree[w2[j]-'a']++;
                    found = true;
                    break;
                }
            }
            // Invalid case: Prefix issue “If the first word is longer than the second word, and the second word is a prefix of the first, then the input is invalid — return an empty string.”
            // ex: if w1 = abcd and w2 = abc then ordering wrong bcz technically in dict if one word is a prefix of the other, the prefix word comes before the other word.  
          if(!found && w1.length() > w2.length())
            return "";
        }
        
        // Step 3: Topo Sort kahn's ALgo
        queue<int> q;
        for(int i=0; i<26; i++)
        {
            if(present[i] && indegree[i] == 0)
            q.push(i);
        }
        string order="";
        
        while(!q.empty())
        {
            int node = q.front();
            order += (char)(node + 'a');
            q.pop();
            
            for(auto adjNode: adj[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                q.push(adjNode);
            }
        }
        // Step 4: Cycle Check
        int totalChars = 0;
        for(bool p:present)
        {
            if(p)
            totalChars++;
        }
        if(order.length() != totalChars) 
         return "";
         
        return order;
    }
};



// If the problem statement is like: Given a sorted dictionary of an alien language having N words and having K starting alphabets of the standard English dictionary.
// Find order of chars in alien language.
// Input: N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output: b d a c


class Solution {
private:
    // Function to perform Topological Sort using Kahn's Algorithm (BFS)
    vector<int> topoSort(int V, vector<int> adj[]) {
        // indegree[i] will store number of incoming edges for node i
        vector<int> indegree(V, 0);

        // Compute indegree of all vertices
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Queue to store all vertices with indegree = 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo; // to store the topological order

        // Process until queue is empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Add this node to result
            topo.push_back(node);

            // For each neighbor, decrease its indegree
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                // If indegree becomes 0, push it into the queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }

public:
    // Function to find the order of characters in the alien dictionary
    string findOrder(string dict[], int N, int K) {
        // Graph represented as adjacency list
        vector<int> adj[K];

        // Build graph by comparing adjacent words in dictionary
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            // Find the first different character and create edge
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break; // only the first mismatch matters
                }
            }
        }

        // Perform topological sort on the graph
        vector<int> topo = topoSort(K, adj);

        // Convert numeric values back to characters
        string ans = "";
        for (auto node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};
