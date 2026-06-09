// Problem: Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/

// Two standard ways to achieve this:

// 1. BFS (Level Order Traversal)
// -> Traverse level by level using a queue.
// -> At each level, record the last node’s value.
// -> Add that to your answer.

// 2. DFS (Recursive Preorder with Right Priority)
// -> Traverse root → right → left.
// -> Keep track of the current depth.
// -> If it’s the first time you’re visiting that depth, record the node’s value.
// -> This ensures the rightmost node at each level is captured.

// TC: O(N) (every node visited once).
// SC: O(H) for DFS (stack depth), or O(N) for BFS (queue in worst case).

// 1st BFS Approach

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightV;
        if(!root)
        return rightV;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            rightV.push_back(temp.back());
        }
        return rightV;
    }
};

// 2nd DFS Approach
// 🪜 How it works
// Depth tracking: Each recursive call carries the current depth.
// First visit rule: If depth == ans.size(), it means we haven’t recorded a node at this level yet → push the current node’s value.
// Right-first traversal: Ensures the rightmost node is seen before any left nodes at the same depth.


class Solution {
public:
    void dfs(TreeNode* node, int depth, vector<int>& ans) {
        if (!node) return;

        // If this is the first time we reach this depth, record the node
        if (depth == ans.size()) {
            ans.push_back(node->val);
        }

        // Go right first, then left
        dfs(node->right, depth + 1, ans);
        dfs(node->left, depth + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
